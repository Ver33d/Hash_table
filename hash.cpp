#include "test.h"
#define BUCKET_HASH 8

Hash::Hash(int b)	
{
    this->BUCKET = b;
    table= new list<int>[BUCKET];
    word = new list<string>[BUCKET];
}

void Hash::search(string _word) {
cout<<endl;
int _key=0,check=0,i=0,p;

	_key=_word.length();
	_key=hashFunction(_key);
	i=_key;
	for(auto x:word[_key]){
		x=x.erase(x.size()-1);
		if(_word.compare(x)==0){
			cout<<"Искомое слово : "<<x<< " И стоит оно в строке № "<<i<<endl;
		check=1;
		break;
		}
	}
	if(check==0){
	 cout<<" - the word was not found in this cell "<<endl;
	}
}

list<string> delete_list_elem(list<string> word, int _key)
{
int i=0;
	list<string>::iterator it = word.begin();
	while(i<=_key)
		{
		if(i==_key)
		{
		cout<< *it <<" ";
		word.remove(*it);
		cout<<"\n deleted"<<endl;
		}
	it++;
	i++;
	}
return word;
}


void Hash::_delete(string _word_2){
cout<<endl;
int _key=0,check=0,l=0;
	_key=_word_2.length();
	_key=hashFunction(_key);

		for(auto y:word[_key]){
			y=y.erase(y.size()-1);
			if(_word_2.compare(y)==0){
				cout<<"Удаляемое слово == "<<y<<endl;
			word[_key]= delete_list_elem(word[_key], check);
			l=1;
			break;
			}
			check++;
		} 
		if(l==0)
		cout<<"Слово, которое вы указали, не присутствует в таблице"<<endl;
}


void Hash::insertItem(string sumbol,int key)
{		
		 int index = hashFunction(key);
    table[index].push_back(key); 
   //cout<<" index == "<<index<<endl;
  word[index].push_back(sumbol);
}

void Hash::displayHash() {	// функция для отображения хеш-таблицы
int check_2=0;
  for (int i = 0; i < BUCKET; i++) {
    cout << i;
    for (auto x : word[i]){
    	if(check_2==0){
     		 cout << " --> " << x;
     		 check_2=1;
     		 }
     	else
     	cout << "      " << x;
     	}
    check_2=0;
      cout<<endl;
  }
}

int main()
{
	int count=0,counter=0;
	int *values=NULL;
	int *num;
	char c;
	std::string str;
	  Hash h(BUCKET_HASH);   // количество сегментов в хеш-таблице 
  cout << "Please type some lines of text. Enter a dot (.) to finish:\n";
  do{
    c = std::cin.get();
    str += c;
    count++;
    if (c=='\n'){
    	counter++;
    	num=(int*)realloc(values,counter*sizeof(int));
    	count-=1;
    	num[counter-1]=count;
      h.insertItem(str,count);
      str.clear();
      count=0;
    }
  }while (c!='.');
  
  h.displayHash();
  char s;
  	string _word;
  	 // do{
   	cout<<"Введите слово, которое нужно найти в хеш-таблице "<<endl;
   	cin>>_word;
  h.search(_word);
 //cout<<"Введите точку, если хотите окончить ввод слов "<<endl;
 // cin>>s;
  // }while (s!='.');
 		string _word_2;
 		// do{
  	cout<<"Введите слово, которое нужно удалить "<<endl;
   	cin>>_word_2;
   	h._delete(_word_2);
   	  h.displayHash();
   	  //cout<<"Введите точку, если хотите окончить ввод слов "<<endl;
 // cin>>s;
  // }while (s!='.');
   	  free(num);
  return 0;
}
