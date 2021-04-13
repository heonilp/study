


vector <string> split(string str, string delimeter)
{
    vector<string> ret;
    string tmp="";
    for (auto s:str)
    {
        if(s==delimeter)
        {
            ret.push_back(tmp);
            tmp="", continue;
        }
        tmp+=s;
    }
    return ret;
}