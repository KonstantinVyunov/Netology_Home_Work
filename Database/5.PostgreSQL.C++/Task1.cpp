#include <pqxx/pqxx>
#include <iostream>
#include <iomanip>
#include <exception>
//#include <Windows.h>
//#pragma execution_character_set("utf-8")

class DataBase {
private:
	pqxx::connection& connection;
public:
	DataBase(pqxx::connection& connection_) : connection(connection_) {}
	DataBase() = delete;
	DataBase(const DataBase& connection) = delete;
	DataBase(DataBase&& connection) = delete;

	DataBase& operator=(const DataBase& connect_obj) = delete;
	DataBase& operator=(DataBase&& connect_obj) = delete;

	void CreateTable(std::string query) {
		pqxx::transaction create_table{ connection };
		create_table.exec(
			"CREATE TABLE IF NOT EXISTS " + create_table.esc(query)
		);

		create_table.commit();
		return;
	}

	void AddUser(std::string str, std::string str1 = "", std::string str2 = "", std::string str3 = "", std::string str4 = "") {
		pqxx::transaction add_user{ connection };
		add_user.exec(
			  "INSERT INTO "+ add_user.esc(str)
			+ " VALUES (" + add_user.esc(str1) + ", '" + add_user.esc(str2) + "', '" + add_user.esc(str3) + "', '" + add_user.esc(str4) + "') "
		);

		add_user.commit();
		return;
	}

	void AddPhone(std::string str, std::string str1 = "", std::string str2 = "", std::string str3 = "") {
		pqxx::transaction add_phone{ connection };
		add_phone.exec(
			  "INSERT INTO "+ add_phone.esc(str)
			+ " VALUES (" + add_phone.esc(str1) + ", "
			+ add_phone.esc(str2) + ", '"
			+ add_phone.esc(str3) + "') "
		);

		add_phone.commit();
		return;
	}

	void UpdateUser(std::string user, std::string query_name, std::string replacing_name, std::string replaced_name) {
		pqxx::transaction update_user{ connection };
		update_user.exec(
			  "UPDATE " + update_user.esc(user)
			+ " SET " + update_user.esc(query_name)
			+ " = '" + update_user.esc(replacing_name)
			+ "' " + "\nWHERE "
			+ update_user.esc(query_name) + " = '"
			+ update_user.esc(replaced_name) + "'"
		);

		update_user.commit();
		return;
	}

	void DeletePhoneNumber( std::string str1, std::string str2) {
		pqxx::transaction delete_phone{ connection };
		delete_phone.exec(
			"DELETE FROM t_fone WHERE "
			+ delete_phone.esc(str1)
			+ " = " + delete_phone.esc(str2)
		);
		
		delete_phone.commit();
		return;
	}

	void DeleteUser(std::string str1, std::string str2) {
		DeletePhoneNumber( str1 + "_fio", str2);
		pqxx::transaction delete_user{ connection };
		delete_user.exec(
			"DELETE FROM fio WHERE "
			+ delete_user.esc(str1)
			+ " = " + delete_user.esc(str2)
		);
		
		delete_user.commit();
		return;
	}

	void SearchUser(std::string str) {
		pqxx::transaction search_user{ connection };
		std::cout << "ID\t"
			<< std::setw(10) << "First Name\t"
			<< std::setw(10) << "Second Name\t"
			<< std::setw(10) << "e-mail\t"
			<< std::setw(6) << "id\t"
			<< std::setw(8) << "Phone Number\n";

		for (auto [ID, first_name, last_name, e_mail, id, tel1] : search_user.query<int, std::string, std::string, std::string, int, std::string>
				(
					"SELECT f.id, f.first_name, f.last_name,f.e_mail, t.id, t.t_fone FROM fio AS f "
					"JOIN t_fone AS t ON f.id = t.id_fio "
					"WHERE (f.first_name = '" + search_user.esc(str) + "' "+
					"OR f.last_name = '" + search_user.esc(str) + "' "+
					"OR f.e_mail = '" + search_user.esc(str) + "' "+
					"OR t.t_fone = '" + search_user.esc(str) + "' )"
				)
			)
		{
			std::cout << ID << '\t' <<
			std::setw(10) << first_name << '\t' <<
			std::setw(10) << last_name << '\t' <<
			std::setw(10) << e_mail << '\t ' <<
			std::setw(6) << id << '\t' <<
			std::setw(8) << tel1 << "\n";
		}

		std::cout << "\n";
		return;
	}

	void DeleteTable(std::string str) {
		pqxx::transaction deleting_table{ connection };
		deleting_table.exec(
			"DROP TABLE " + deleting_table.esc(str)
		);
										
		deleting_table.commit();
		return;
	}

	void PrintOutTable() {
		pqxx::transaction print_table{ connection };
		std::cout << "ID\t"
				  << std::setw(10) << "First Name\t"
				  << std::setw(10) << "Second Name\t"
				  << std::setw(10) << "e-mail\t"
				  << std::setw(6)  << "id\t"
				  << std::setw(8)  << "Phone Number\n";

		for (auto &[ID, first_name, last_name, e_mail, id, tel1] : print_table.query<int, std::string, std::string, std::string, int, std::string>
				(
					"SELECT f.id, f.first_name, f.last_name, f.e_mail, t.id, t.t_fone FROM fio AS f "
					"JOIN t_fone as t on f.id = t.id_fio"
				)
			)
		{
		    std::cout << ID << '\t' <<
			std::setw(10) << first_name << '\t' <<
			std::setw(10) << last_name << '\t' <<
			std::setw(10) << e_mail << '\t ' <<
			std::setw(6) << id << '\t' <<
			std::setw(8) << tel1 << "\n";
		}

		std::cout << "\n";
		return;
	}

	~DataBase() {}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(CP_UTF8);
	//SetConsoleOutputCP(CP_UTF8);
	//setvbuf(stdout, nullptr, _IOFBF, 1'000);

	try	{
		pqxx::connection connect_obj("host=localhost "
									 "port = 5432 "
									 "dbname = postgres "
									 "user = postgres "
									 "password = finik");

		DataBase data_base(connect_obj);

		data_base.CreateTable(
			"fio(id int PRIMARY KEY NOT NULL, "
			"first_name varchar(30) NOT NULL, "
			"last_name varchar(30) NOT NULL, "
			"e_mail varchar(50))"
		);

		data_base.CreateTable(
			"t_fone(id int PRIMARY KEY NOT NULL, "
			"id_fio int references fio (id), "
			"t_fone varchar(20))"
		);
		
		data_base.AddUser(
			"fio(id, first_name, last_name, e_mail)", 
			"1",
			"Andrey",
			"Ivanov",
			"ai@m.ru"
		);
		
		data_base.AddUser(
			"fio(id, first_name, last_name,e_mail)",
			"2",
			"Sergey",
			"Petrov",
			"sp@g.com"
		);

		data_base.AddUser(
			"fio(id, first_name, last_name,e_mail)",
			"3",
			"Vasiliy",
			"Sidorov",
			"vs@y.ru"
		);

		data_base.AddUser(
			"fio(id, first_name, last_name,e_mail)",
			"4",
			"Dmitriy",
			"Rogov",
			"dr@r.ru"
		);


		data_base.AddPhone("t_fone(id, id_fio, t_fone)", "1", "1", "+7991");
		data_base.AddPhone("t_fone(id, id_fio, t_fone)", "2", "1", "");
		data_base.AddPhone("t_fone(id, id_fio, t_fone)", "3", "2", "+7992");
		data_base.AddPhone("t_fone(id, id_fio, t_fone)", "4", "3", "+7993");
		data_base.AddPhone("t_fone(id, id_fio, t_fone)", "5", "3", "+7994");
		data_base.AddPhone("t_fone(id, id_fio, t_fone)", "6", "4", "+7998");

		std::cout << "\t\t\tINITIAL BASE VIEW\n";
		data_base.PrintOutTable();
		
		std::cout << "\t\t\tUPDATE NAMES\n\t\t('Andrey' replaced with 'Griha')\n";
		data_base.UpdateUser("fio", "first_name", "Griha", "Andrey");
		data_base.PrintOutTable();
		
		std::cout << "\t\t\tDELETE USER WITH PHONE id=1\n";
		data_base.DeletePhoneNumber("id","1");
		data_base.PrintOutTable();
		
		std::cout << "\t\t\tDELETE USER WITH ID=1\n";
		data_base.DeleteUser( "id", "1");
		data_base.PrintOutTable();

		std::cout << "\t\t\tQUERY USER NAME: Sergey\n";
		data_base.SearchUser("Sergey");
		std::cout << "\t\t\tQUERY USER LAST NAME: Sidorov\n";
		data_base.SearchUser("Sidorov");
		std::cout << "\t\t\tQUERY USER E-MAIL: dr@r.ru'\n";
		data_base.SearchUser("dr@r.ru");
		std::cout << "\t\t\tQUERY USER PHONE: +7993\n";
		data_base.SearchUser("+7993");

		data_base.DeleteTable("t_fone");
		data_base.DeleteTable("fio");
		

	} catch (std::exception& error) {
		std::cerr << error.what() << std::endl;
	}

	return EXIT_SUCCESS;
}