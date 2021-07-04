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
 if (ist.bad()) error("ist is bad"); // stream corrupted; let’s get out of here!
 if (ist.fail()) { // clean up the mess as best we can and report the problem
 ist.clear(); // clear stream state,
 // so that we can look for terminator
 char c;
 ist>>c; // read a character, hopefully terminator
 if (c != terminator) { // unexpected character
 ist.unget(); // put that character back
 ist.clear(ios_base::failbit); // set the state to fail()
 }
 }
}
