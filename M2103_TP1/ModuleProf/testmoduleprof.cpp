/*
 * Je n'ai pas réussi à régler les dernières erreurs.
 */

#include <iostream>
#include <vector>

using namespace std;

namespace {

    class Prof;
    class Module;

    class Prof {
    private:

        // Attributes
        string myName;

    public:

        // Attributes
        vector <Module *> myModules; // Modules enseignés par le prof

        // Constructor
        Prof (const string &name) noexcept;

        // Operations
        void   display (); // Affiche le nom du prof
        void   addModule (Module * module);
        string getName ();
        void   setName (string & name);

    }; // Duree

    class Module {
    private:

        // Attributes
        string myName;

    public:

        // Attributes
        vector <Prof *> myProfs; // Profs enseignants ce module

        // Constructor
        Module (const string &name) noexcept;

        // Operations
        void   display (); // Affiche le nom du module
        void   addProf (Prof * prof);
        string getName ();
        void   setName (string & name);

    }; // Module

    //---- Prof operations ----//
    Prof::Prof (const string &name) noexcept
    {
        Prof::myName = name;
    } // Prof Constructor

    void Prof::display()
    {
        for (Module *module : myModules)
        {
            cout << module->getName() << endl;
        }
    } // Prof::display

    void Prof::addModule(Module * module)
    {
        myModules.push_back(module);
    } // Prof::addModule

    string Prof::getName()
    {
        return myName;
    } // Prof::getName

    void Prof::setName(string & name)
    {
        myName = name;
    } // Prof::setName


    //---- Module operations ----//
    Module::Module (const string &name) noexcept
    {
        Module::myName = name;
    } // Module Constructor

    void Module::display()
    {
        for (Prof *prof : myProfs)
        {
            cout << prof->getName() << endl;
        }
    } // Module::display

    void Module::addProf(Prof * prof)
    {
        myProfs.push_back(prof);
    } // Module::addProf

    string Module::getName()
    {
        return myName;
    } // Module::getName

    void Module::setName(string & name)
    {
        myName = name;
    } // Module::setName

    //---- ----//
    void testModuleProf()
    {
        vector <Module *> vectModules;
        vector <Prof *> vectProfs;

        // Création d'un vecteur de modules
        for (unsigned i = 0; i < 5; i++)
        {
            string nomModule;

            cout << "Entrez le nom du module " << i+1 << " : ";
            getline(cin, nomModule);
            cout << endl;

            Module *unModule = new Module (nomModule);
            vectModules.push_back(unModule);
        }

        // Création d'un vecteur de profs
        for (unsigned i = 0; i < 5; i++)
        {
            string nomProf;

            cout << "Entrez le nom du prof " << i+1 << " : ";
            getline(cin, nomProf);
            cout << endl;

            Prof *unProf = new Prof (nomProf);
            vectProfs.push_back(unProf);
        }

        // Création de 2 modules
        Module *Test1Module = new Module ("ModuleDeTest1");
        Module *Test2Module = new Module("ModuleDeTest2");

        // Ajout de ces modules à tous les profs
        for (Prof *prof : vectProfs)
        {
            prof->addModule(Test1Module);
            prof->addModule(Test2Module);
        }

        // Création de 2 profs
        Prof *Test1Prof = new Prof ("ProfDeTest1");
        Prof *Test2Prof = new Prof ("ProfDeTest2");

        // Ajout de ces profs à tous les modules
        for (Module *module : vectModules)
        {
            module->addProf(Test1Prof);
            module->addProf(Test2Prof);
        }

        // Affichage des profs et leurs modules
        for (Prof *prof : vectProfs)
        {
            cout << "++" << prof->getName() << endl;
            prof->display();
        }

        // Affichage des modules et leurs profs
        for (Module *module : vectModules)
        {
            cout << "++" << module->getName() << endl;
            module->display();
        }

        for (Module *module : vectModules)
        {
            delete module;
        }

        for (Prof *prof : vectProfs)
        {
            delete prof;
        }

    }
} // namespace
