#include<iostream>
#include <list>
#include <cstring>

using namespace std;

class Hash
{
    int CELL;		  
    list<int> *table;		 				// Указатель на массив, содержащий сегменты
    list<string> *word;	
public:
    Hash(int V);  							// Конструктор
    void insertItem(string sumbol, int key);// вставляем ключ в хеш-таблицу  
    int hashFunction(int x) {   			// хеш-функция для сопоставления значений с ключом
		return (x % CELL);	 
    }
    void search(string _word);
    void _delete(string _word_2);
    void displayHash();
};
 
