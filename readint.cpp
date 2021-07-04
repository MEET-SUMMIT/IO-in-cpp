#include ".\std_lib_facilities.h"
void fill_vector(istream& ist, vector<int>& v, char terminator);
int main(){
    cout<<"enter the file name to read:";
    string iname;
    cin>>iname;
    ifstream ist{iname};
    if (!ist) error("can't open input file ",iname);

    vector <int> v;
    fill_vector(ist,v,'*');
    return 0;
}
void fill_vector(istream& ist, vector<int>& v, char terminator)
 // read integers from ist into v until we reach eof() or terminator
{
 for (int i; ist >> i; ) v.push_back(i);
 for(int j=0;j<v.size();j++)
  cout<<v[j];
 if (ist.eof()) return; // fine: we found the end of file
 // not good() and not bad() and not eof(), ist must be fail()
 ist.clear(); // clear stream state
 char c;
 ist>>c; // read a character, hopefully terminator
 if (c != terminator) { // ouch: not the terminator, so we must fail
 ist.unget(); // maybe my caller can use that character
 ist.clear(ios_base::failbit); // set the state to fail()
 }
}
