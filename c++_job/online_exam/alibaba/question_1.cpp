#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

void trans(string &str , int &number)
{
    stringstream stream(str);
    stream >> number;
}

void trans(string &str , float &number)
{
    stringstream stream(str);
    stream >> number;
}

void trans(string &str , string &number)
{
    stringstream stream(str);
    stream >> number;
}

template<typename T>
vector<T> split(const string &str,const string &pattern,T datatype)
{
    //const char* convert to char*
    char * strc = new char[strlen(str.c_str())+1];
    strcpy(strc, str.c_str());
    vector<T> resultVec;
    char* tmpStr = strtok(strc, pattern.c_str());
    while (tmpStr != NULL)
    {
        T number;
        string tmp_str = string(tmpStr);
        trans(tmp_str,number);
        resultVec.push_back(number);
        tmpStr = strtok(NULL, pattern.c_str());
    }

    delete[] strc;

    return resultVec;
}

int main(int argc, const char *argv[])
{
    string info_str;
    string input_info;
    getline(cin,info_str);
    getline(cin,input_info);
    string type = "";
    vector<string> name_infos = split(info_str,";",type);
    map<string,string> name_names_map;
    
    for (auto iter = name_infos.begin(); iter != name_infos.end(); ++iter) 
    {
        string name_info = *iter;
        vector<string> name_names = split(name_info,"_",type);
        if (name_names.size() == 2)
        {
            string name = name_names[0];
            string names = name_names[1];
            vector<string> names_vec = split(names,"|",type);
            for (auto iter_name =names_vec.begin(); iter_name != names_vec.end(); ++iter_name) 
            {
                if(name_names_map.find(*iter_name) != name_names_map.end())
                {
                    string name_old = name_names_map[*iter_name];
                    name_names_map[*iter_name] = name_old + "," + name;
                }
                else
                    name_names_map[*iter_name] = name;
            } 
        }
    }

    for (auto iter_map = name_names_map.begin(); iter_map != name_names_map.end(); ++iter_map) 
    {
        size_t found = input_info.find(iter_map->first);
        int len = (iter_map->first).size();
        string name = "";
        if(found != string::npos)
        {
            name = input_info.substr(found,len);
            string replace_str = " "+name+"/"+iter_map->second+" ";
            input_info = input_info.replace(found,len,replace_str);
        }
    }

    cout << input_info << endl;

    return 0;
}
