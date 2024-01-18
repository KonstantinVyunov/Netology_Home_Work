#pragma once
#include"Classes.h"

void INSERT_PUBL(Wt::Dbo::Session& obj1, std::string str) {
    Wt::Dbo::Transaction transaction{ obj1 };
    auto a = std::make_unique<Publisher>(Publisher());
    a->name = str;
    obj1.add(std::move(a));
    transaction.commit();
}

void INSERT_SHOP(Wt::Dbo::Session& obj1, int id, std::string str) {
    Wt::Dbo::Transaction transaction{ obj1 };
    auto a = std::make_unique<Shop>(Shop());
    a->id = id;
    a->name = str;
    obj1.add(std::move(a));
    transaction.commit();
}

void INSERT_BOOK(Wt::Dbo::Session& obj1, std::string title, std::string name_id) {
    Wt::Dbo::Transaction transaction{ obj1 };
    auto a = std::make_unique< Book>(Book());
    a->title = title;
    a->publisher = obj1.find<Publisher>().where("name = ? ").bind(name_id);
    obj1.add(std::move(a));
    transaction.commit();
}

void INSERT_STOCK(Wt::Dbo::Session& obj1, std::string book, std::string shop, int count) {
    Wt::Dbo::Transaction transaction{ obj1 };
    auto a = std::make_unique<Stock>(Stock());
    a->book = obj1.find<Book>().where("title = ?").bind(book);
    a->shop = obj1.find<Shop>().where("name = ?").bind(shop);
    a->count = count;
    obj1.add(std::move(a));
    transaction.commit();
}

void INSERT_SALE(Wt::Dbo::Session& obj1, std::string price, std::string data_sale, std::string stock, int count) {
    Wt::Dbo::Transaction transaction{ obj1 };
    auto a = std::make_unique<Sale>(Sale());
    a->price = price;
    a->data_sale = data_sale;
    a->stock = obj1.find<Stock>().where("count = ?").bind(stock);
    a->count = count;
    obj1.add(std::move(a));
    transaction.commit();
}
