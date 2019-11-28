#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "IDatabaseHandler.h"
#include "SqliteDatabaseHandler.h"

typedef std::unordered_map< std::string, std::string > Row;
typedef std::vector< Row > Table;
int main()
{
    IDatabaseHandler* dbh = new SqliteDatabaseHandler();
    dbh->prepareQuery("CREATE TABLE IF NOT EXISTS Provinces (id INTEGER PRIMARY KEY, uuid TEXT, name TEXT, code TEXT)");
    dbh->prepareQuery("CREATE TABLE IF NOT EXISTS Parties (id INTEGER PRIMARY KEY, uuid TEXT, name TEXT, code TEXT, provinces_id INTEGER, FOREIGN KEY(provinces_id) REFERENCES Provinces(id) )");
    dbh->prepareQuery("CREATE TABLE IF NOT EXISTS Towns (id INTEGER PRIMARY KEY, uuid TEXT, name TEXT, postal_code TEXT, parties_id INTEGER, FOREIGN KEY(parties_id) REFERENCES Parties(id))");
    dbh->execute();

    dbh->prepareQuery("INSERT INTO Towns(id, uuid, name, postal_code, parties_id) VALUES(?, ?, ?, ?, ?)");
    dbh->addParameter(1, "1");
    dbh->addParameter(2, "1530");
    dbh->addParameter(3, "Mar de Cobo");
    dbh->addParameter(4, "5600");
    dbh->addParameter(5, "15");
    dbh->execute();

    dbh->prepareQuery("INSERT INTO Parties(id, uuid, name, code, provinces_id) VALUES(?, ?, ?, ?, ?)");
    dbh->addParameter(1, "15");
    dbh->addParameter(2, "1537");
    dbh->addParameter(3, "Mar Chiquita");
    dbh->addParameter(4, "42");
    dbh->addParameter(5, "1");
    dbh->execute();

    dbh->prepareQuery("INSERT INTO Provinces(id, uuid, name, code) VALUES(?, ?, ?, ?)");
    dbh->addParameter(1, "1");
    dbh->addParameter(2, "2");
    dbh->addParameter(3, "Buenos Aires");
    dbh->addParameter(4, "1");
    dbh->execute();

    //ROW DATA:
    dbh->prepareQuery("SELECT * FROM Towns WHERE id=?");
    dbh->addParameter(1, "1");
    Row row = dbh->fetch();

    std::cout << "ROW DATA 1" << std::endl;
    std::cout << "id: " << row["id"] << std::endl;
    std::cout << "uuid: " << row["uuid"] << std::endl;
    std::cout << "name: " << row["name"] << std::endl;
    std::cout << "postal_code: " << row["postal_code"] << std::endl;
    std::cout << "parties_id: " << row["parties_id"] << std::endl << std::endl;

    dbh->prepareQuery("SELECT * FROM Towns");
    Table table = dbh->fetchAll();

    std::cout << "Table DATA row 1:" << std::endl;
    std::cout << "id: " << table[0]["id"] << std::endl;
    std::cout << "uuid: " << table[0]["uuid"] << std::endl;
    std::cout << "name: " << table[0]["name"] << std::endl;
    std::cout << "postal_code: " << table[0]["postal_code"] << std::endl;
    std::cout << "parties_id: " << table[0]["parties_id"] << std::endl << std::endl;



    //ROW DATA PARTIES:
    dbh->prepareQuery("SELECT * FROM Parties WHERE id=?");
    dbh->addParameter(1, "1");
    Row rowp = dbh->fetch();

    std::cout << "ROW DATA 2" << std::endl;
    std::cout << "id: " << rowp["id"] << std::endl;
    std::cout << "uuid: " << rowp["uuid"] << std::endl;
    std::cout << "name: " << rowp["name"] << std::endl;
    std::cout << "code: " << rowp["code"] << std::endl;
    std::cout << "provinces_id: " << rowp["provinces_id"] << std::endl << std::endl;

    dbh->prepareQuery("SELECT * FROM Parties");
    Table tablep = dbh->fetchAll();

    std::cout << "Table DATA row 2:" << std::endl;
    std::cout << "id: " << tablep[0]["id"] << std::endl;
    std::cout << "uuid: " << tablep[0]["uuid"] << std::endl;
    std::cout << "name: " << tablep[0]["name"] << std::endl;
    std::cout << "code: " << tablep[0]["code"] << std::endl;
    std::cout << "provinces_id: " << tablep[0]["provinces_id"] << std::endl << std::endl;

    //ROW DATA PROVINCES:
    dbh->prepareQuery("SELECT * FROM Provinces WHERE id=?");
    dbh->addParameter(1, "1");
    Row rowpr = dbh->fetch();

    std::cout << "ROW DATA 3" << std::endl;
    std::cout << "id: " << rowpr["id"] << std::endl;
    std::cout << "uuid: " << rowpr["uuid"] << std::endl;
    std::cout << "name: " << rowpr["name"] << std::endl;
    std::cout << "code: " << rowpr["code"] << std::endl << std::endl;

    dbh->prepareQuery("SELECT * FROM Provinces");
    Table tablepr = dbh->fetchAll();

    std::cout << "Table DATA row 3:" << std::endl;
    std::cout << "id: " << tablepr[0]["id"] << std::endl;
    std::cout << "uuid: " << tablepr[0]["uuid"] << std::endl;
    std::cout << "name: " << tablepr[0]["name"] << std::endl;
    std::cout << "code: " << tablepr[0]["code"] << std::endl << std::endl;

    delete dbh;
    return 0;
}