#pragma once
#include <iostream>
#include <exception>
#include <Windows.h>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>


class Book;
class Stock;
class Sale;

class Publisher {
public:
    std::string name = "";
    Wt::Dbo::collection<Wt::Dbo::ptr<Book>>book;
    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, book, Wt::Dbo::ManyToOne, "publisher");
    }
};

class Book {
public:
    std::string title;
    Wt::Dbo::ptr<Publisher> publisher;
    Wt::Dbo::collection< Wt::Dbo::ptr<Stock>> stock;
    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, "publisher");
        Wt::Dbo::hasMany(a, stock, Wt::Dbo::ManyToOne, "book");
    }
};

class Shop {
public:
    int id = 0;
    std::string name = "";
    Wt::Dbo::collection< Wt::Dbo::ptr<Stock> > stock;
    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, stock, Wt::Dbo::ManyToOne, "shop");
    }
};

class Stock {
public:
    int count = 0;
    Wt::Dbo::collection< Wt::Dbo::ptr<Sale> > sale;
    Wt::Dbo::ptr<Book> book;
    Wt::Dbo::ptr<Shop> shop;
    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::belongsTo(a, book, "book");
        Wt::Dbo::belongsTo(a, shop, "shop");
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::hasMany(a, sale, Wt::Dbo::ManyToOne, "stock");
    }
};

class Sale {
public:
    std::string price = "";
    std::string data_sale = "";
    int count = 0;
    Wt::Dbo::ptr<Stock> stock;
    template<class Action>
    void persist(Action& a) {
        Wt::Dbo::field(a, price, "price");
        Wt::Dbo::field(a, data_sale, "data_sale");
        Wt::Dbo::belongsTo(a, stock, "stock");
        Wt::Dbo::field(a, count, "count");
    }
};
