#include <pqxx/pqxx>
#include <iostream>
#include <iomanip>
#include <exception>

class DataBase {
private:
	pqxx::connection& connect_obj;
public:
	DataBase(pqxx::connection& connection) : connect_obj(connection) {}
	DataBase() = delete;
	DataBase(const DataBase& connect_obj) = delete;
	DataBase(DataBase&& connect_obj) = delete;

	DataBase& operator=(const DataBase& connect_obj) = delete;
	DataBase& operator=(DataBase&& connect_obj) = delete;

	void CreateTable(std::string sql_query) {
		pqxx::transaction transaction_create_table{ connect_obj };
		transaction_create_table.exec(
			"CREATE TABLE IF NOT EXISTS " + transaction_create_table.esc(sql_query)
		);

		transaction_create_table.commit();
		return;
	}

	void InsertName(std::string str, std::string str1 = "", std::string str2 = "", std::string str3 = "", std::string str4 = "") {
		pqxx::transaction transaction_insert_name{ connect_obj };
		transaction_insert_name.exec(
			"insert into "+ transaction_insert_name.esc(str)
			+ " values (" + transaction_insert_name.esc(str1) + ", '"
			+ transaction_insert_name.esc(str2) + "', '"
			+ transaction_insert_name.esc(str3) + "', '"
			+ transaction_insert_name.esc(str4) + "') "
		);

		transaction_insert_name.commit();
		return;
	}

	void InsertPhoneNumber(std::string str, std::string str1 = "", std::string str2 = "", std::string str3 = "") {
		pqxx::transaction transaction_insert_phone{ connect_obj };
		transaction_insert_phone.exec(
			"insert into "+ transaction_insert_phone.esc(str)
			+ " values (" + transaction_insert_phone.esc(str1) + ", "
			+ transaction_insert_phone.esc(str2) + ", '"
			+ transaction_insert_phone.esc(str3) + "') "
		);

		transaction_insert_phone.commit();
		return;
	}

	void Update(std::string str1, std::string str2, std::string str3, std::string str4) {
		pqxx::transaction transaction_update{ connect_obj };
		transaction_update.exec(
			"update " + transaction_update.esc(str1)
			+ " set " + transaction_update.esc(str2)
			+ "='" + transaction_update.esc(str3)
			+ "' " + " where "
			+ transaction_update.esc(str2) + "='"
			+ transaction_update.esc(str4) + "'"
		);

		transaction_update.commit();
		return;
	}

	void DeletePhone( std::string str1, std::string str2) {
		pqxx::transaction transaction_delete_phone{ connect_obj };
		transaction_delete_phone.exec(
			"delete from T_FONE  where "
			+ transaction_delete_phone.esc(str1)
			+ " = " + transaction_delete_phone.esc(str2)
		);
		
		transaction_delete_phone.commit();
		return;
	}

	void DeleteName(std::string str1, std::string str2) {
		DeletePhone( str1 + "_fio", str2);
		pqxx::transaction transaction_delete_name{ connect_obj };
		transaction_delete_name.exec(
			"delete from FIO where "
			+ transaction_delete_name.esc(str1)
			+ " = " + transaction_delete_name.esc(str2)
		);
		
		transaction_delete_name.commit();
		return;
	}

	void Search(std::string str) {
		pqxx::transaction transaction_search{ connect_obj };
		std::cout << "id    Имя      Фамилия   почта   id  телефон  \n";

		for (auto [id, first_name, last_name, e_mail, t_id, tel1] : transaction_search.query<int, std::string, std::string, std::string, int, std::string>
				(
					"SELECT f.id, f.first_name, f.last_name,f.e_mail, t.id, t.t_fone FROM FIO as f "
					"join T_FONE as t on f.id = t.id_fio "
					"where (f.first_name = '" + transaction_search.esc(str) + "' "+
					"or f.last_name = '" + transaction_search.esc(str) + "' "+
					"or f.e_mail = '" + transaction_search.esc(str) + "' "+
					"or t.t_fone = '" + transaction_search.esc(str) + "' )"
				)
			)
		{
			std::cout << id <<
			std::setw(10) << first_name <<
			std::setw(10) << last_name <<
			std::setw(10) << e_mail <<
			std::setw(3)  << t_id <<
			std::setw(8)  << tel1 << "\n";
		}

		std::cout << "\n";
		return;
	}

	void DeleteTable(std::string str) {
		pqxx::transaction transaction_deleting_table{ connect_obj };
		transaction_deleting_table.exec(
			"drop table " + transaction_deleting_table.esc(str)
		);
										
		transaction_deleting_table.commit();
		return;
	}

	void PrintOutTable() {
		pqxx::transaction transaction_printing_table{ connect_obj };
		std::cout << "id    Имя      Фамилия   почта   id  телефон  \n";

		for (auto [id, first_name, last_name, e_mail, t_id, tel1] : transaction_printing_table.query<int, std::string, std::string, std::string, int, std::string>
				(
					"SELECT f.id, f.first_name, f.last_name, f.e_mail, t.id, t.t_fone FROM FIO as f "
					"join T_FONE as t on f.id = t.id_fio"
				)
			)
		{
			std::cout << id <<
			std::setw(10) << first_name <<
			std::setw(10) << last_name <<
			std::setw(10) << e_mail <<
			std::setw(3) << t_id <<
			std::setw(8) << tel1 << "\n";
		}

		std::cout << "\n";
		return;
	}
};


int main()
{
	setlocale(0, "");

	try	{
		pqxx::connection connect_obj("host=localhost port=5432 dbname=test user=postgres password=finik");
		DataBase data_base(connect_obj);

		data_base.CreateTable(
			"FIO(id int PRIMARY KEY not null, "
			"first_name varchar(30) not null, "
			"last_name varchar(30) not null, "
			"e_mail varchar(50))"
		);
		data_base.CreateTable(
			"T_FONE(id int PRIMARY KEY not null, "
			"id_fio int references FIO (id), "
			"t_fone varchar(20))"
		);
		data_base.InsertName(
			"FIO(id, first_name, last_name,e_mail) ", 
			"1 ",
			"Andrey ",
			"Ivanov ",
			"ai@m.ru"
		);


		data_base.InsertName(
			"FIO(id, first_name, last_name,e_mail)", "2", "Sergey", "Petrov","sp@g.com"
		);
		data_base.InsertName(
			"FIO(id, first_name, last_name,e_mail)",  "3", "Vasiliy", "Sidorov","vs@y.ru"
		);
		data_base.InsertName(
			"FIO(id, first_name, last_name,e_mail)",  "4", "Dmitriy", "Rogov","dr@r.ru"
		);


		data_base.InsertPhoneNumber(
			"T_FONE(id, id_fio, t_fone)",  "1", "1", "+7991");
		data_base.InsertPhoneNumber(
			"T_FONE(id, id_fio, t_fone)",  "2", "1", ""
		);
		data_base.InsertPhoneNumber(
			"T_FONE(id, id_fio, t_fone)",  "3", "2", "+7992"
		);
		data_base.InsertPhoneNumber(
			"T_FONE(id, id_fio, t_fone)",  "4", "3", "+7993"
		);
		data_base.InsertPhoneNumber(
			"T_FONE(id, id_fio, t_fone)",  "5", "3", "+7994"
		);
		data_base.InsertPhoneNumber(
			"T_FONE(id, id_fio, t_fone)",  "6", "4", "+7998"
		);

		std::cout << "Начальный вид базы\n";
		data_base.PrintOutTable();
		
		std::cout << "UPDATE 'Andrey' на 'Griha'\n";
		data_base.Update("FIO", "first_name", "Griha", "Andrey");
		data_base.PrintOutTable();
		
		std::cout << "DELETE_STR_T_FONE удаление строки c телефоном 'id=1'\n";
		data_base.DeletePhone("id"," 1 ");
		data_base.PrintOutTable();
		
		std::cout << "DELETE_STR_FIO удаление строки c клиентом 'id=1'\n";
		data_base.DeleteName( "id", "1");
		data_base.PrintOutTable();

		std::cout << "Поиск по имени 'Sergey'\n";
		data_base.Search("Sergey");
		std::cout << "Поиск по фамилии 'Sidorov'\n";
		data_base.Search("Sidorov");
		std::cout << "Поиск по почте 'dr@r.ru'\n";
		data_base.Search("dr@r.ru");
		std::cout << "Поиск по номеру телефона '+7993'\n";
		data_base.Search("+7993");

		data_base.DeleteTable("T_FONE");
		data_base.DeleteTable("FIO");


	} catch (std::exception& error) {
		std::cerr << error.what() << std::endl;
	}

	return EXIT_SUCCESS;
}