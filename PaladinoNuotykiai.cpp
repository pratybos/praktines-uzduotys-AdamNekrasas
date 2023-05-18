#include <iostream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

int level = 1;
int experience = 0;

void gainExperience(int amount) {
    experience += amount;
    cout << "===============" << endl;
    cout << "Gavot " << amount << " patirties tasku!" << endl;

    while (experience >= 100) {
        level++;
        experience -= 100;
        cout << "===============" << endl;
        cout << "Jus paseket nauja lygi! Dabartinis lygis: " << level << endl;
        cout << "===============" << endl;
    }
    int remainingExp = 100 - experience;
    cout << "Patirties tasku iki naujo lygio: " << remainingExp << endl;
    cout << "Isviso: " << experience << endl;
    cout << "===============" << endl;
}

class Achievement
{
public:
    std::string name;
    std::string description;

    Achievement(const std::string& achievementName, const std::string& achievementDescription)
        : name(achievementName), description(achievementDescription) {}
};

class AchievementSystem
{
private:
    std::vector<Achievement> achievements;

public:
    void unlockAchievement(const std::string& name, const std::string& description)
    {
        Achievement achievement(name, description);
        achievements.push_back(achievement);
        std::cout << "Pasiekimas atrakintas: " << name << " - " << description << std::endl;
    }

    void displayAchievements()
    {
        if (achievements.empty())
        {
            std::cout << "Pasiekimu nera." << std::endl;
        }
        else
        {
            std::cout << "Pasiekimai:" << std::endl;
            for (const Achievement& achievement : achievements)
            {
                std::cout << "- " << achievement.name << " - " << achievement.description << std::endl;
            }
        }
    }
};

class Item
{
public:
    string name;
    string type;

    Item(string itemName, string type) : name(itemName), type(type) {}
};

class Loot
{
    vector<Item*> items;

public:
    Loot()
    {
        LoadItems();
    }

    void LoadItems()
    {
        items.push_back(new Item("Plieninis", "kardas"));
        items.push_back(new Item("Gelezinis kardas", "kardas"));
        items.push_back(new Item("Kuvalda", "kardas"));
        items.push_back(new Item("Legendinis kardas", "kardas"));
        items.push_back(new Item("Plieninis Salmas", "salmas"));
        items.push_back(new Item("Gelezinis Salmas", "salmas"));
        items.push_back(new Item("Odinis Salmas", "salmas"));
        items.push_back(new Item("Legendinis Salmas", "salmas"));
        items.push_back(new Item("Plieniniai Sarvai", "sarvai"));
        items.push_back(new Item("Geleziniai Sarvai", "sarvai"));
        items.push_back(new Item("Odiniai Sarvai", "sarvai"));
        items.push_back(new Item("Legendiniai Sarvai", "sarvai"));
    }

    Item* GetRandomLoot()
    {
        int itemPos = rand() % items.size();
        return items[itemPos];
    }
};

class Inventory
{
public:
    vector<Item*> items;

    void addItem(Item* item)
    {
        items.push_back(item);
    }

    void removeItem(string itemType)
    {
        for (Item* item: items)
        {
            if (item->type == itemType)
            {
                items.erase(find(items.begin(), items.end(), item));
                break;
            }
        }
    }

    void displayItems()
    {
        if (items.empty())
        {
            cout << "Inventorius yra tuðcias." << endl;
        }
        else
        {
            cout << "===============" << endl;
            cout << "Jusu Inventorius:" << endl;
            cout << "===============" << endl;
            for (Item* item : items)
            {
                cout << "- " << item->name << endl;
            }
            cout << "===============" << endl;
        }
    }
};

void rodytiMeniu(bool arPradetasZaidimas)
{
    cout << "===============" << endl;
    if (!arPradetasZaidimas)
    {
        cout << "1. Pradeti zaidima" << endl;
        cout << "0. Iseiti" << endl;
    }
    else
    {
        cout << "Zaidimas jau pradetas!" << endl;
    }
    //cout << "0. Iseiti" << endl;
    // cout << "===============" << endl;
}

int main()
{
    srand(time(NULL));
    Loot* loot = new Loot();
    Inventory inventory;
    AchievementSystem achievementSystem;

    Item* sword = new Item("Paprastas kardas", "kardas");
    inventory.addItem(sword);
//    Item* armor = new Item("Paprasti sarvai");
//    inventory.addItem(armor);


    cout << "Sveiki atvyke i zaidima! Siuzetas: Jus vardu Jeanas Pierre'as, tamplieru ordeno paladinas (sviesos karys)" << endl;
    cout << "kuris karaliaus isakymu eina i apleista pili  kad susiduoruot su vietiniu vampyru" << endl;

    int pasirinkimas;
    bool zaidimasVyksta = true;
    bool arPradetasZaidimas = false;

    while (zaidimasVyksta)
    {
        rodytiMeniu(arPradetasZaidimas);

        cout << "Iveskite pasirinkima: ";
        cin >> pasirinkimas;
        switch (pasirinkimas)
        {
        case 1:
            if (!arPradetasZaidimas)
            {

                cout << "Pradedame zaidima!" << endl;
                cout << "Jeanas Pierre'as pasiekia apleistaja pili ir pamazu pradeda tyrinti aplinkui." << endl;
                cout << "Pilis tamsi ir griaudejanti, o ið tolimo girdisi nezinomos kilmes snabzdesiai." << endl;
                cout << "Jums tenka rasti buda sviesai pasiekti vidu ir iveikti pili apnikusius monstrus." << endl;

                char degaluPasirinkimas;
                bool degaluUzpildyta = false;
                bool tinkamaspasirinkimas = false;
                do
                {
                    cout << "===============" << endl;
                    cout << "Jums pavyksta rasti senovini degalu buteli, bet jis tuscias. Kaip ji uzpildysite?" << endl;
                    cout << "A. Uzpildysiu vandeniu is saltinio" << endl;
                    cout << "B. Uzpildysiu aliejumi, kuri radau netoli" << endl;
                    cout << "C. Paieskosiu kitu degalu saltiniu" << endl;
                    cout << "Iveskite pasirinkima: ";


                    cin >> degaluPasirinkimas;
                    cout << "===============" << endl;
                    switch (degaluPasirinkimas)
                    {
                    case 'A':
                    case 'a':
                    case 'B':
                    case 'b':
                        cout << "Uzpildete buteli " << ((degaluPasirinkimas == 'A' || degaluPasirinkimas == 'a') ? "vandeniu is saltinio." : "aliejumi, kuri radote netoli.") << endl;
                        tinkamaspasirinkimas = true;
                        break;
                    case 'C':
                    case 'c':
                        cout << "Nusprendete ieskoti kitu degalu saltiniu." << endl;
                        cout << "Jus pasiseke rasti daugiau degalu buteliuku ant backos su aliejum ir situ buteliuku jums bus gana iki keliones pabaigos" << endl;
                        tinkamaspasirinkimas = true;


                        degaluUzpildyta = true;
                        break;
                    default:
                        cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
                        break;
                    }
                }
                while (!tinkamaspasirinkimas);

                if (degaluUzpildyta)
                {
                    cout << "Paspaudete buteliui dangteli ir nusprendete testi savo kelione." << endl;
                    achievementSystem.unlockAchievement("Ðviesus kelias", "Jus radot kuom uþpildyt degalu buteli");
                }

                Item* degalai = new Item("Degalu butelis", "fuel");
                inventory.addItem(degalai);
                inventory.displayItems();

                cout << "===============" << endl;
                cout << "Prasciau matote tamsia liuka ir girdite keistus garsus is jo." << endl;
                cout << "Ka darysite?" << endl;
                cout << "A. Ieiti i liuka." << endl;
                cout << "B. Apziureti aplinkui ieskant alternatyviu budu testi kelione." << endl;
                cout << "===============" << endl;

                char urvoPasirinkimas;
                bool pasirinkimas2 = false;
                bool turiRakta = false;
                do
                {
                    cout << "Iveskite pasirinkima: ";
                    cin >> urvoPasirinkimas;


                    switch (urvoPasirinkimas)
                    {
                    case 'A':
                    case 'a':
                        cout << "Nusprendete ueiti i liuka ir suzinoti, kas ten slepiasi." << endl;
                        cout << "Pastebite rakta, kuris yra istriges uþ liuko. Ir paimate ji" << endl;
                        turiRakta = true;
                        pasirinkimas2 = true;
                        break;
                    case 'B':
                    case 'b':
                        cout << "Nusprendete apziureti aplinkui ieskant alternatyviu budu testi kelione." << endl;

                        cout << "Iðtyres aplinka, nerandate nieko, kas galetu padeti.Griþtate prie liuko" << endl;
                        cout << "Pastebite rakta, kuris yra istriges uþ liuko. Ir paimate ji" << endl;
                        turiRakta = true;
                        pasirinkimas2=true;
                        break;
                    default:
                        cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
                        break;
                    }
                }
                while (!pasirinkimas2);

                bool pasirinkimas3 = false;

                if (turiRakta)
                {
                    cout << "===============" << endl;
                    cout << "Su raktu jus atidaruot, durys kurie buvo uzdaryti anksciau uz ju jusu laukia 3 skeletai" << endl;
                    int skeletuSkaicius = 3;
                    if (skeletuSkaicius > 0)
                    {
                        do
                        {
                            cout << "Jus susidurete su " << skeletuSkaicius << " skeletais." << endl;
                            cout << "Kaip norite su jais susidoroti?" << endl;
                            cout << "A. Pulti kardu" << endl;
                            cout << "B. Naudoti magija" << endl;
                            cout << "C. Begti (begant zaidimas baigesi)" << endl;
                            cout << "Iveskite pasirinkima: ";


                            char pasirinkimas;
                            cin >> pasirinkimas;

                            switch (pasirinkimas)
                            {
                            case 'A':
                            case 'a':
                            case 'B':
                            case 'b':
                                cout << "===============" << endl;
                                cout << "Jus sekmingai susidorojete su skeletais ir tesiat savo kelia" << endl;
                                pasirinkimas3 = true;
                                break;
                            case 'C':
                            case 'c':
                                cout << "===============" << endl;
                                cout << "Pabegant nuo skeletu jus neivygdet savo misijos ir todel baiget zaidima!" << endl;
                                pasirinkimas3 = true;
                                zaidimasVyksta = false;
                                break;
                            default:
                                cout << "===============" << endl;
                                cout << "Neteisingas pasirinkimas. Bandykite dar karta." << endl;
                                break;
                            }

                        }
                        while (!pasirinkimas3);
                    }
                }

                achievementSystem.unlockAchievement("Pirmi priesininkai", "Jus nukovet pirmus priesininkus");

                gainExperience(25);

                bool rastasLegendarusKardas = true;
                bool arLegendinsKardasPaimtas = false;

                if (rastasLegendarusKardas)
                {
                    Item* foundItem = loot->GetRandomLoot();
                    cout << "Po musio su skeletais jus praeinant i kita kambari pilies centre jus radot " <<  foundItem->name << "! Tai galingas ginklas, kuris suteikia ypatingas galias." << endl;
                    //todo: prideti exp
                    // exp->calculate(50);
                    //void calculate(int exp)
                    //{
                      //    experiance += exp;
                    //}

                    do
                    {
                        cout << "Norite naudotis " << foundItem->name << "? (Taip/Ne): ";
                        string pasirinkimas;
                        cin >> pasirinkimas;

                        if (pasirinkimas == "Taip" || pasirinkimas == "taip")
                        {

                            cout << "Jus pasirinkote naudotis " << foundItem->name << " Jusu galiu jega sustipreja." << endl;
                            arLegendinsKardasPaimtas = true;

                            //Item* legendarysword = new Item("Legendinis kardas");
                            inventory.removeItem(foundItem->type);
                            inventory.addItem(foundItem);
                            inventory.displayItems();

                            //delete sword;
                            break;
                        }
                        else if (pasirinkimas == "Ne" || pasirinkimas == "ne")
                        {
                            cout << "Jus nusprendete neremti " << foundItem->name << " Ginkite save kitaip." << endl;
                            arLegendinsKardasPaimtas = false;

                            inventory.displayItems();
                            break;
                        }
                        else
                        {
                            cout << "Neteisingas pasirinkimas." << endl;
                        }
                    }
                    while (true);
                }
                else
                {
                    cout << "Kambario viduje nieko ypatingo nerasta." << endl;
                }

                bool laimetaKova = false;

                while (!laimetaKova)
                {
                    cout << "Jusu raktas kuri jis radote anksciau atrodo kad gali atidaryti bet kokius durys sitoj pilij." << endl;
                    cout << "Jus atidaruot pagrindine duri salieje ir praeinat toliau,aplinkui jus matot daug kaulu ir kraujo." << endl;
                    cout << "Tamsoj jus matote du siluetus jus be baimes einat arciau." << endl;
                    cout << "Pries jus stovi galingas nekromantas ir jo issauktas skeletas su sarvais." << endl;
                    cout << "Skeletas pradeda jus pulti" << endl;

                    cout << "===============" << endl;

                    cout << "Pasirinkite, ka darysite:" << endl;
                    cout << "1. Atakuoti skeleta su sarvais" << endl;
                    cout << "2. Bandyti issisukti nuo atakos" << endl;
                    cout << "3. Pabegti nuo kovos (begant zaidimas baigesi)" << endl;

                    cout << "===============" << endl;

                    int veiksmas;
                    cout << "Iveskite veiksmo numeri: ";
                    cin >> veiksmas;

                    switch (veiksmas)
                    {
                    case 1:
                    {
                        bool breakWhile = false;

                        do
                        {
                            cout << "Pultote skeleta su sarvais!" << endl;
                            cout << "Bet skeletas irgi speja jums duot smugi dar viena toki jus ne pergyvensit" << endl;
                            cout << "===============" << endl;
                            cout << "5. Atakuoti kardu." << endl;
                            cout << "6. Atakuoti sviesos burtu." << endl;
                            cout << "7. Issisukt ir kontratakuot." << endl;
                            cout << "8. Pabegti (zaidimas baigesi.)" << endl;
                            cout << "Iveskite pasirinkima: ";
                            cin >> pasirinkimas;

                            switch (pasirinkimas)
                            {
                            case 5:
                                cout << "===============" << endl;
                                cout << "Atakuojant kardu skeletas nukautas bet jis irgi speja jums duot kritini smugi ir jus mirstat." << endl;
                                cout << "===============" << endl;
                                cout << "Zaidimas baigesi." << endl;
                                laimetaKova = true;
                                zaidimasVyksta = false;
                                breakWhile = true;
                                break;
                            case 6:
                                cout << "===============" << endl;
                                cout << "Atakuojant sviesos burtu jus nukaunat skeleta, skeletas net ne spejo pajudet." << endl;
                                cout << "Po sekundes jus pastebejot kad nekromantas prapuole ir matot tik atidarytas durys pro kurias jis galymai pabego." << endl;
                                cout << "===============" << endl;
                                laimetaKova = true;
                                breakWhile = true;
                                break;
                            case 7:
                                cout << "===============" << endl;
                                cout << "Jus pasirinkot palaukt skeleto smugio, skeletas pradeda jus atakuot, bet ataka per leta ir jus issisukat ir kontratakuojat skeleta." << endl;
                                cout << "Skeletas griuna." << endl;
                                cout << "Po sekundes jus pastebejot kad nekromantas prapuole ir matot tik atidarytas durys pro kurias jis galymai pabego." << endl;
                                cout << "===============" << endl;
                                laimetaKova = true;
                                breakWhile = true;
                                break;
                            case 8:
                                cout << "===============" << endl;
                                cout << "jus nusprendziate pabegt ir zaidimas baigesi." << endl;
                                laimetaKova = true;
                                zaidimasVyksta = false;
                                breakWhile = true;
                                break;
                            default:
                                cout << "Neteisingas veiksmo numeris. Bandykite dar karta." << endl;
                                cout << "===============" << endl;
                                break;
                            }
                        }
                        while (!breakWhile);

                        break;
                    }
                    case 2:
                        cout << "Bandoma issisukti nuo atakos!" << endl;
                        cout << "===============" << endl;
                        cout << "Issisukant jus randat galimybe greitai susiduorot su nekromantu." << endl;
                        cout << "Nukauntant nekromanta skeletas griuna pats." << endl;
                        cout << "===============" << endl;
                        laimetaKova = true;
                        break;
                    case 3:
                        cout << "Begate nuo kovos!" << endl;
                        cout << "Zaidimas baigesi!" << endl;
                        cout << "===============" << endl;
                        laimetaKova = true;
                        zaidimasVyksta = false;
                        break;
                    default:
                        cout << "Neteisingas veiksmo numeris. Bandykite dar karta." << endl;
                        cout << "===============" << endl;
                        break;
                    }
                }
                achievementSystem.unlockAchievement("Net sarvai ne pades", "Jus nukovet nekromanta ir sarvota skeleta");

                gainExperience(75);

                bool rastiUzburtiSarvai = true;
                bool arUzburtiSarvaipaimti = false;


                if (rastiUzburtiSarvai)
                {
                    do
                    {
                        // todo: change text
                        Item* foundItem = loot->GetRandomLoot();
                        cout << "Laimint musi pries skeleta ir nekromanta, jus pastebejot kad skeletono sarvai yra uzburti ir jums gali prireikt" << endl;
                        cout << "Ar norite paimti " << foundItem->name << " ? (Taip/Ne): " << endl;


                        string pasirinkimas;
                        cin >> pasirinkimas;

                        if (pasirinkimas == "Taip" || pasirinkimas == "taip")
                        {

                            cout << "Jus pasirinkote naudotis " << foundItem->name << " ! Jusu galiu jega sustipreja." << endl;
                            //Item* enchantedarmor = new Item("Uzburti sarvai");
                            inventory.removeItem(foundItem->type);
                            inventory.addItem(foundItem);
                            inventory.displayItems();
                            arUzburtiSarvaipaimti = true;
                            break;
                        }
                        else if (pasirinkimas == "Ne" || pasirinkimas == "ne")
                        {
                            // todo: change text
                            cout << "Jus nusprendete neimti uzburtais sarvais. Jus einate toliau." << endl;
                            arUzburtiSarvaipaimti = false;

                            inventory.displayItems();
                            break;
                        }
                        else
                        {
                            cout << "Darykite pasirinkima dar karta" << endl;
                        }
                    }
                    while(true);
                }
                else
                {
                    cout << "Kambario viduje nieko ypatingo nerasta." << endl;
                    break;
                }

                bool laimetaKovaVampyro = false;

                while (zaidimasVyksta)
                {

                    while (!laimetaKovaVampyro)
                    {
                        cout << "Personazas, ginkluotas galingu kardu ir su dideliu patirties kiekiu, pasiekia salta ir tamsia pilies sosto dali," << endl;
                        cout << "Zinodamas, kad vampyras uzsitese sioje vietoje." << endl;
                        cout << "Personazas izengia i pilies sosto dali ir pajunta slapcius saltus gurksnius ore, kurie rodo vampyro buvima.." << endl;
                        cout << "Vampyras pasirodo is tamsos, jo raudonos akys zibant baisiai." << endl;
                        cout << "Personazas pasiruoses kovai, sujuda i prieki ir isipainioja i mirtine kova su vampyru." << endl;

                        cout << "===============" << endl;

                        cout << "Pasirinkite, ka darysite:" << endl;
                        cout << "1. Atakuoti vampyra" << endl;
                        cout << "2. Atakuot sviesos magija" << endl;
                        cout << "3. Bandyti issisukti nuo atakos" << endl;
                        cout << "4. Pabegti nuo kovos (begant zaidimas baigesi)" << endl;

                        cout << "===============" << endl;

                        int veiksmas;
                        cout << "Iveskite veiksmo numeri: ";
                        cin >> veiksmas;
                        bool wybor=false;

                        switch (veiksmas)
                        {
                        case 1:
                            do
                            {

                                cout << "Jus atakuojat vampyra, kova yra intesivi bet jis prasileidzia smugi nuo jusu kardo" << endl;
                                cout << "Vampyra bando jus kontratakuot" << endl;
                                cout << "Ka darysit toliau" << endl;
                                cout << "===============" << endl;
                                cout << "5. Atakuoti kardu." << endl;
                                cout << "6. Atakuoti sviesos burtu." << endl;
                                cout << "7. Issisukt nuo ir kontratakuot." << endl;
                                cout << "8. Pabegti (zaidimas baigesi.)" << endl;
                                cout << "Iveskite pasirinkima: ";
                                cin >> pasirinkimas;

                                switch (pasirinkimas)
                                {
                                case 5:
                                    do
                                    {
                                        cout << "===============" << endl;
                                        cout << "Atakuojant kardu vampyra." << endl;
                                        cout << "Jus pataikot anksciau i vampyra nei jis speja jus" << endl;
                                        cout << "Atrodo kad dar vienas smugis vampyrui bus paskutinis" << endl;
                                        cout << "===============" << endl;
                                        int x;
                                        cout << "Pasirinkite, ka darysite:" << endl;
                                        cout << "1. Atakuoti kardu." << endl;
                                        cout << "2. Atakuoti sviesos burtu." << endl;
                                        cout << "3. Pabegti (zaidimas baigesi.)" << endl;
                                        cout << "Iveskite pasirinkima: ";
                                        cin >> x;

                                        switch (x)
                                        {
                                        case 1:
                                            cout << "===============" << endl;
                                            cout << "Just atakuojat vampyra ir nugalyt ji" << endl;
                                            achievementSystem.unlockAchievement("Ausros sviesa", "Jus nukovet vampyra ir praejot zaidima ");
                                            gainExperience(100);
                                            cout << "===============" << endl;
                                            cout << "Sveikinus zaidimas baigtas!" << endl;

                                            laimetaKovaVampyro = true;
                                            zaidimasVyksta = false;
                                            break;
                                        case 2:
                                            cout << "===============" << endl;
                                            cout << "Jus puolat vampyra su sviesos magija ir nugalyt ji" << endl;
                                            achievementSystem.unlockAchievement("Ausros sviesa", "Jus nukovet vampyra ir praejot zaidima ");
                                            gainExperience(100);
                                            cout << "===============" << endl;
                                            cout << "Sveikinus zaidimas baigtas!" << endl;
                                            laimetaKovaVampyro = true;
                                            zaidimasVyksta = false;
                                            break;
                                        case 3:
                                            cout << "Begate nuo kovos,bet vampyras yra greitis, jis jus pasivija ir nuzudo is galo!" << endl;
                                            cout << "===============" << endl;
                                            laimetaKovaVampyro = true;
                                            zaidimasVyksta = false;
                                            break;
                                        }

                                    }
                                    while(!laimetaKovaVampyro);

                                    break;
                                case 6:

                                    cout << "===============" << endl;
                                    cout << "Atakuojant sviesos burtu vampyra jus ji nukaunate." << endl;
                                    achievementSystem.unlockAchievement("Ausros sviesa", "Jus nukovet vampyra ir praejot zaidima ");
                                    gainExperience(100);
                                    cout << "===============" << endl;
                                    cout << "Sveikinus zaidimas baigtas" << endl;
                                    cout << "===============" << endl;


                                    laimetaKovaVampyro = true;
                                    zaidimasVyksta = false;
                                    break;

                                case 7:
                                    cout << "===============" << endl;
                                    cout << "Jus pasirinkot palaukt vampyro smugio ir kontratakuot, jus pamatot ta vienintele galimybe nusisukt ir ta padarote." << endl;
                                    cout << "Jus pamatot vampyro silpna vieta ir smugiojete i ja" << endl;
                                    cout << "Po sekundes vampyro kunas griuna, jus laimejote." << endl;
                                    achievementSystem.unlockAchievement("Ausros sviesa", "Jus nukovet vampyra ir praejot zaidima ");
                                    gainExperience(100);
                                    cout << "===============" << endl;
                                    cout << "Sveikinus zaidimas baigtas" << endl;

                                    cout << "===============" << endl;

                                    laimetaKovaVampyro = true;
                                    zaidimasVyksta = false;
                                    break;
                                case 8:
                                    cout << "===============" << endl;
                                    cout << "jus nusprendziate pabegt ir zaidimas baigesi." << endl;
                                    laimetaKovaVampyro = true;
                                    zaidimasVyksta = false;
                                    break;
                                default:
                                    cout << "Neteisingas veiksmo numeris. Bandykite dar karta." << endl;
                                    cout << "===============" << endl;
                                    break;

                                }

                            }
                            while(!laimetaKovaVampyro);

                            break;
                        case 2:
                            do
                            {
                                cout << "Jus smugiojat vampyra su sviesos burtu, tai daro daug zalos." << endl;
                                cout << "Dar viena smugi vampyras ne isgyvens" << endl;
                                cout << "===============" << endl;
                                cout << "===============" << endl;
                                int y;
                                cout << "Pasirinkite, ka darysite:" << endl;
                                cout << "1. Atakuoti kardu." << endl;
                                cout << "2. Atakuoti sviesos burtu." << endl;
                                cout << "3. Pabegti (zaidimas baigesi.)" << endl;
                                cout << "Iveskite pasirinkima: ";
                                cin >> y;

                                switch (y)
                                {
                                case 1:
                                    cout << "===============" << endl;
                                    cout << "Just atakuojat vampyra ir nugalyt ji" << endl;
                                    achievementSystem.unlockAchievement("Ausros sviesa", "Jus nukovet vampyra ir praejot zaidima ");
                                    gainExperience(100);
                                    cout << "===============" << endl;
                                    cout << "Sveikinus zaidimas baigtas!" << endl;

                                    laimetaKovaVampyro = true;
                                    zaidimasVyksta = false;
                                    break;
                                case 2:
                                    cout << "===============" << endl;
                                    cout << "Jus puolat vampyra su sviesos magija ir nugalyt ji" << endl;
                                    achievementSystem.unlockAchievement("Ausros sviesa", "Jus nukovet vampyra ir praejot zaidima ");
                                    gainExperience(100);
                                    cout << "===============" << endl;
                                    cout << "Sveikinus zaidimas baigtas!" << endl;

                                    laimetaKovaVampyro = true;
                                    zaidimasVyksta = false;
                                    break;
                                case 3:
                                    cout << "Begate nuo kovos,bet vampyras yra greitis, jis jus pasivija ir nuzudo is galo!" << endl;
                                    cout << "===============" << endl;
                                    laimetaKovaVampyro = true;
                                    zaidimasVyksta = false;
                                    break;
                                }
                            }
                            while(!laimetaKovaVampyro);
                            break;
                        case 3:
                            do
                            {

                            cout << "Jus pasirinkot palaukt vampyro smugio ir kontratakuot, jus pamatot ta vienintele galimybe nusisukt ir ta padarote." << endl;
                            cout << "Jus pamatot vampyro silpna vieta ir smugiojete i ja" << endl;

                            cout << "Dar viena smugi vampyras ne isgyvens" << endl;
                            cout << "===============" << endl;
                            int z;
                            cout << "Pasirinkite, ka darysite:" << endl;
                            cout << "1. Atakuoti kardu." << endl;
                            cout << "2. Atakuoti sviesos burtu." << endl;
                            cout << "3. Pabegti (zaidimas baigesi.)" << endl;
                            cout << "Iveskite pasirinkima: ";
                            cin >> z;

                            switch (z)
                            {
                            case 1:
                                cout << "===============" << endl;
                                cout << "Just atakuojat vampyra ir nugalyt ji" << endl;
                                achievementSystem.unlockAchievement("Ausros sviesa", "Jus nukovet vampyra ir praejot zaidima ");
                                cout << "===============" << endl;
                                cout << "Sveikinus zaidimas baigtas!" << endl;

                                laimetaKovaVampyro = true;
                                zaidimasVyksta = false;
                                break;
                            case 2:
                                cout << "===============" << endl;
                                cout << "Jus puolat vampyra su sviesos magija ir nugalyt ji" << endl;
                                achievementSystem.unlockAchievement("Ausros sviesa", "Jus nukovet vampyra ir praejot zaidima ");
                                gainExperience(100);
                                cout << "===============" << endl;
                                cout << "Sveikinus zaidimas baigtas!" << endl;

                                laimetaKovaVampyro = true;
                                zaidimasVyksta = false;
                                break;
                            case 3:
                                cout << "Begate nuo kovos,bet vampyras yra greitis, jis jus pasivija ir nuzudo is galo!" << endl;
                                cout << "===============" << endl;
                                laimetaKovaVampyro = true;
                                zaidimasVyksta = false;
                                break;
                            }
                            }while(!laimetaKovaVampyro);
                            break;
                        case 4:

                            cout << "Begate nuo kovos,bet vampyras yra greitis, jis jus pasivija ir nuzudo is galo!" << endl;
                            cout << "===============" << endl;
                            laimetaKovaVampyro = true;
                            zaidimasVyksta = false;
                            break;
                        default:
                            cout << "Neteisingas veiksmo numeris. Bandykite dar karta." << endl;
                            cout << "===============" << endl;
                            break;
                        }
                    }

                }
                achievementSystem.displayAchievements();



                arPradetasZaidimas = true;
            }
            else
            {
                cout << "Zaidimas jau pradetas!" << endl;
            }
            break;

        case 0:
            cout << "Iseiname is zaidimo. Viso gero!" << endl;
            zaidimasVyksta = false;
            break;
        default:
            cout << "Netinkamas pasirinkimas. Bandykite dar karta." << endl;
            break;
        }

        cout << "===============" << endl;
    }
    return 0;
}
