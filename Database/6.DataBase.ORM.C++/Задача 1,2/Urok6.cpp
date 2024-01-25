#include"Insert.h"


int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    try {
        std::string connectionString = "host=localhost port=5432 dbname=TEST user=postgres password=12345678";

        auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(connectionString);
        Wt::Dbo::Session session;

        session.setConnection(std::move(postgres));
        session.mapClass<Publisher>("publisher");
        session.mapClass<Book>("book");
        session.mapClass<Shop>("shop");
        session.mapClass<Sale>("sale");
        session.mapClass<Stock>("stock");
        try {
            session.createTables();
        }
        catch (const  Wt::Dbo::Exception& e) {}
        Wt::Dbo::Transaction t{ session };
        Wt::Dbo::collection<Wt::Dbo::ptr<Publisher>> p = session.find<Publisher>();
        t.commit();
        if (p.empty()) {
            INSERT_PUBL(session, "Andrey");
            INSERT_PUBL(session, "Sergey");

            INSERT_BOOK(session, "book_andr_1", "Andrey");
            INSERT_BOOK(session, "book_andr_2", "Andrey");
            INSERT_BOOK(session, "book_andr_3", "Andrey");
            INSERT_BOOK(session, "book_serg_1", "Sergey");
            INSERT_BOOK(session, "book_serg_2", "Sergey");

            INSERT_SHOP(session, 1, "MAGAZ_1");
            INSERT_SHOP(session, 2, "MAGAZ_2");
            INSERT_SHOP(session, 3, "MAGAZ_3");

            INSERT_STOCK(session, "book_andr_1", "MAGAZ_1", 5);
            INSERT_STOCK(session, "book_andr_1", "MAGAZ_2", 4);
            INSERT_STOCK(session, "book_andr_2", "MAGAZ_1", 6);
            INSERT_STOCK(session, "book_andr_2", "MAGAZ_2", 1);
            INSERT_STOCK(session, "book_andr_3", "MAGAZ_2", 12);
            INSERT_STOCK(session, "book_andr_3", "MAGAZ_3", 11);
            INSERT_STOCK(session, "book_serg_1", "MAGAZ_3", 8);
            INSERT_STOCK(session, "book_serg_2", "MAGAZ_1", 2);

            INSERT_SALE(session, "10", "10.10.12", "5", 1);
            INSERT_SALE(session, "12", "12.10.12", "4", 1);
            INSERT_SALE(session, "20", "13.10.12", "6", 1);
            INSERT_SALE(session, "22", "14.10.12", "1", 1);
            INSERT_SALE(session, "15", "15.10.12", "12", 1);
            INSERT_SALE(session, "17", "17.10.12", "11", 1);
            INSERT_SALE(session, "50", "19.10.12", "8", 1);
            INSERT_SALE(session, "60", "20.10.12", "2", 1);
        }
        
        std::string name;
        std::cout << "ведите имя издателя: ";
        std::cin >> name;

        Wt::Dbo::Transaction transaction{ session };
        Wt::Dbo::collection<Wt::Dbo::ptr<Publisher>> publishers = session.find<Publisher>().where("name = ?").bind(name);
        std::vector<Wt::Dbo::ptr<Stock>> stocks;
        if (!publishers.empty())
            for (auto p : publishers) {
                for (auto b : p->book) {
                    std::for_each(b->stock.begin(), b->stock.end(), [&stocks](Wt::Dbo::ptr<Stock> s) { stocks.push_back(s); ; });
                }
            }
        else std::cout << "Нет такого издателя" << std::endl;
        for (auto stock : stocks) {
            std::cout<<"Издатель " << name << " : " << stock->book->title << " Магазин: " << stock->shop->name << std::endl;
        }
        transaction.commit();
    }
    catch (const  Wt::Dbo::Exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

