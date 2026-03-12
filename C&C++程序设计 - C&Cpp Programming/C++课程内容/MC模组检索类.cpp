#include<iostream>
#include<string>
using namespace std;

class ModInfo
{
    private:
        string Modid;
        int MCVersion;
        int ModVersion;
        char DevVersion;
    public:
        void signin(string name, int mcv, int mdv, int dvv);
        int getMCV()  {return MCVersion;}
        int getMdV()  {return ModVersion;}
        char getDvV() {return DevVersion;}
};

void ModInfo::signin(string name, int mcv, int mdv, int dvv)
{
    Modid = name;
    MCVersion = mcv;
    ModVersion = mdv;
    DevVersion = dvv;
}

class Library
{
    private:
        string Modsid[100];
        int MCVersions[100];
        int ModVersion[100];
        char DevVersion[100];
}
