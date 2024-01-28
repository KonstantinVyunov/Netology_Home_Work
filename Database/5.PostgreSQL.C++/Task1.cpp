#include <iostream>
#include <iomanip>
#include <exception>
#include <pqxx/pqxx>

class BD {
private:
	pqxx::connection& obj;
public:
	BD(pqxx::connection& obj) :obj(obj) {}
	BD() = delete;
	BD(const BD& obj) = delete;
	BD(BD&& obj) = delete;
	BD& operator=(const BD& obj) = delete;
	BD& operator=(BD&& obj) = delete;

	void CREATE_TABLE(std::string str) {
		pqxx::work w{obj};
		w.exec("create table if not exists " + w.esc(str));
		w.commit();
	}

	void INSERT_FIO(std::string str, std::string str1 = "", std::string str2 = "", std::string str3 = "", std::string str4 = "") {
		pqxx::work w{obj};
		w.exec("insert into " + w.esc(str) + " values (" + w.esc(str1) + ", '" + w.esc(str2) + "', '" + w.esc(str3) + "', '" + w.esc(str4) + "') ");
		w.commit();
	}
	void INSERT_T_FONE(std::string str, std::string str1 = "", std::string str2 = "", std::string str3 = "") {
		pqxx::work w{obj};
		w.exec("insert into " + w.esc(str) + " values (" + w.esc(str1) + ", " + w.esc(str2) + ", '" + w.esc(str3)+ "') ");
		w.commit();
	}

	void UPDATE(std::string str1, std::string str2, std::string str3, std::string str4) {
		pqxx::work w{obj};
		w.exec("update " + w.esc(str1) +" set "+ w.esc(str2)+ "='" + w.esc(str3) + "' " + " where " + w.esc(str2)+"='"+ w.esc(str4)+"'");
		w.commit();
	}
	void DELETE_STR_T_FONE( std::string str1, std::string str2) {
		pqxx::work w{obj};
		w.exec("delete from T_FONE  where " + w.esc(str1) + " = " + w.esc(str2));
		w.commit();
	}
	void DELETE_STR_FIO(std::string str1, std::string str2) {
		DELETE_STR_T_FONE( str1 + "_fio", str2);
		pqxx::work w{obj};
		w.exec("delete from FIO where " + w.esc(str1) + " = " + w.esc(str2));
		w.commit();
	}
	void POISK(std::string str) {
		pqxx::work w{obj};
		std::cout << "id    Имя      Фамилия   почта   id  телефон  \n";
		for (auto [id, first_name, last_name, e_mail, t_id, tel1] : w.query<int, std::string, std::string, std::string, int, std::string >(
			"SELECT f.id, f.first_name, f.last_name,f.e_mail, t.id, t.t_fone FROM FIO as f "
			"join T_FONE as t on f.id = t.id_fio "
		    "where (f.first_name = '" + w.esc(str) + "' "+
			"or f.last_name = '" + w.esc(str) + "' "+
			"or f.e_mail = '" + w.esc(str) + "' "+
			"or t.t_fone = '" + w.esc(str) + "' )"))
		{
			std::cout << id << std::setw(10) << first_name << std::setw(10) << last_name << std::setw(10) << e_mail << std::setw(3) << t_id << std::setw(8) << tel1 << "\n";
		}
		std::cout << "\n";
	}
	void DELETE_TABLE(std::string str) {
		pqxx::work w{obj};
		w.exec("drop table " + w.esc(str));
		w.commit();
	}
	void PRINT_BD() {
		pqxx::work w{obj};
		std::cout << "id    Имя      Фамилия   почта   id  телефон  \n";
		for (auto [id, first_name, last_name, e_mail, t_id, tel1] : w.query<int, std::string, std::string, std::string, int, std::string >(
			"SELECT f.id, f.first_name, f.last_name,f.e_mail, t.id, t.t_fone FROM FIO as f "
			"join T_FONE as t on f.id = t.id_fio"))
		{
			std::cout << id << std::setw(10) << first_name << std::setw(10) << last_name << std::setw(10) << e_mail << std::setw(3) << t_id << std::setw(8) << tel1 << "\n";
		}
		std::cout << "\n";
	}
};


int main()
{
	setlocale(0, "");
	try	{
		pqxx::connection c("host=localhost port=5432 dbname=TEST user=postgres password=12345678");
		BD bd(c);
		bd.CREATE_TABLE("FIO(id int PRIMARY KEY not null,"
			                "first_name varchar(30) not null,"
			                "last_name varchar(30) not null,"
			                "e_mail varchar(50))");		
		bd.CREATE_TABLE("T_FONE(id int PRIMARY KEY not null,"
			                   "id_fio int references FIO (id),"
			                   "t_fone varchar(20))");
		bd.INSERT_FIO("FIO(id, first_name, last_name,e_mail )", "1", "Andrey", "Ivanov", "ai@m.ru");
		bd.INSERT_FIO("FIO(id, first_name, last_name,e_mail)", "2", "Sergey", "Petrov","sp@g.com");
		bd.INSERT_FIO("FIO(id, first_name, last_name,e_mail)",  "3", "Vasiliy", "Sidorov","vs@y.ru");
		bd.INSERT_FIO("FIO(id, first_name, last_name,e_mail)",  "4", "Dmitriy", "Rogov","dr@r.ru");

		bd.INSERT_T_FONE("T_FONE(id, id_fio, t_fone)",  "1", "1", "+7991");
		bd.INSERT_T_FONE("T_FONE(id, id_fio, t_fone)",  "2", "1", "");
		bd.INSERT_T_FONE("T_FONE(id, id_fio, t_fone)",  "3", "2", "+7992");
		bd.INSERT_T_FONE("T_FONE(id, id_fio, t_fone)",  "4", "3", "+7993");
		bd.INSERT_T_FONE("T_FONE(id, id_fio, t_fone)",  "5", "3", "+7994");
		bd.INSERT_T_FONE("T_FONE(id, id_fio, t_fone)",  "6", "4", "+7998");	
		std::cout << "Начальный вид базы\n";
		bd.PRINT_BD();
		
		bd.UPDATE("FIO", "first_name","Griha", "Andrey");	
		std::cout << "UPDATE 'Andrey' на 'Griha'\n";
		bd.PRINT_BD();
		
		bd.DELETE_STR_T_FONE("id"," 1 ");
		std::cout << "DELETE_STR_T_FONE удаление строки с телефоном 'id=1'\n";
		bd.PRINT_BD();
		
		bd.DELETE_STR_FIO( "id", "1");
		std::cout << "DELETE_STR_FIO удаление строки с клиентом 'id=1'\n";
		bd.PRINT_BD();

		std::cout << "Поиск по имени 'Sergey'\n";
		bd.POISK("Sergey");
		std::cout << "Поиск по фамилии 'Sidorov'\n";
		bd.POISK("Sidorov");
		std::cout << "Поиск по почте 'dr@r.ru'\n";
		bd.POISK("dr@r.ru");
		std::cout << "Поиск по номеру телефона '+7993'\n";
		bd.POISK("+7993");	

		bd.DELETE_TABLE("T_FONE");
		bd.DELETE_TABLE("FIO");


	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}