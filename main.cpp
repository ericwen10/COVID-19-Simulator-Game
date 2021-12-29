
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>
using namespace std;

int main()
{
    int LabRats =0, DNA =0, Chemical =0, ResearchPoints=0;
    double Money =2000000;
    const int RATCOST =15, DNACOST =110, CHEMICALCOST =120, MediaExposureCost = 1600000, DedicatedScientistCost = 1600000;
    double MainMenuChoice, StoreChoice;
    int NewRatamountmin=0, NewRatamountmax=1000, NewDNAamountmin=0, NewDNAamountmax=1000, NewChemicalamountmin=0, NewChemicalamountmax=1000; ///newrat amount, newDNAamount, newChemicalamount
    int Days=0, NewRatAmount =250, NewDNAAmount = 200, NewChemicalAmount =200, ResearchPointGain = 1, scientistmin=0, scientistmax=10;
    int max = 100, min = 0;
    int ResearchPointPercentage, Quantity;
    bool MediaExposure = false,DedicatedScientist = false;
    int UpgradeCount = 0, Location = 1, CanadaDonation = 250000, ChinaDonation = 500000, UnitedStatesDonation = 1000000;

do
{
    system ("cls");
    cout << "\tWelcome to the Covid-19 Research Effort\n";                                  ///setting up the Main Menus
    cout << "=================================================================" << endl;

    cout << "\tLabRats:\t" << LabRats << endl;
    cout << "\tDNA:\t\t" << DNA << endl;
    cout << "\tChemical:\t" << Chemical << endl;
    cout << "\tMoney:\t\t" << setprecision(2) << fixed << Money << endl;
    cout << "=================================================================" << endl;
    cout << "\tResearch Points:" << setprecision(1) << fixed << ResearchPoints << "\tDays:" << Days << endl;
    cout << "=================================================================" << endl;
    cout << "\tUpgrades: ";
        if (UpgradeCount == 0)                                                              ///Checking if user has upgrades
            cout << "\tNone" << endl;
        if (MediaExposure == true)
            cout <<"\tMedia Exposure\n";
        if (DedicatedScientist == true)
            cout << "\t\t\tDedicatedScientist\n";
    cout << "=================================================================" << endl;
    cout << "\tCurrent Location: ";
            if (Location == 1)
                cout << "Canada" << endl;                                                  ///Checking user location

            if (Location == 2)
                cout << "China" << endl;
            if (Location ==3)
                cout << "United States" << endl;
    cout << "=================================================================" << endl;

    cout << "\tMain Menu:\n";
    cout << "================================================================="<< endl;    ///MainMenu
    cout << "\t0. Exit the game.\n";
    cout << "\t1. Go to the Shop.\n";
    cout << "\t2. Simulate One Day\n";
    cout << "\t3. Buy Upgrades\n";
    cout << "\t4. Crisis Analyzation\n";
    cout << "\t5. Change Labroatory Locations\n" << endl;

    cout << "What would you like to do? ";
    cin >> MainMenuChoice;


    if(MainMenuChoice == 1)///Go to the store
    {
        do
        {
            system ("cls");
            cout << "\tWelcome to the Covid-19 Research Effort\n";
            cout << "=================================================================" << endl;

            cout << "\tLabRats:\t" << LabRats << endl;
            cout << "\tDNA:\t\t" << DNA << endl;
            cout << "\tChemical:\t" << Chemical << endl;
            cout << "\tMoney:\t\t" << setprecision(2) << fixed << Money << endl;
            cout << "=================================================================" << endl;
            cout << "\tResearch Points:" << setprecision(1) << fixed << ResearchPoints << "\tDays:" << Days << endl;
            cout << "=================================================================" << endl;
            cout << "\tUpgrades: ";
                if (UpgradeCount == 0)
                    cout << "None" << endl;
                if (MediaExposure == true)
                    cout <<"\tMedia Exposure\n";
                if (DedicatedScientist == true)
                    cout << "\t\t\tDedicatedScientist\n" << endl;
            cout << "\tCurrent Location: ";
                if (Location == 1)
                    cout << "Canada." << endl;
                if (Location == 2)
                cout << "China." << endl;
                if (Location == 3)
                    cout << "United States." << endl;
            cout << "=================================================================" << endl;
            cout << "\tWelcome to the Labratory shop: " << endl;
            cout << "=================================================================" << endl;
            cout << "\t0.Exit the store.\n";
            cout << "\t1. Buy Lab Rats: $15\n";
            cout << "\t2. Buy DNA: $110\n";
            cout << "\t3. Buy Chemical: $150\n";
            cin  >> StoreChoice;

            if(StoreChoice==1)///Buy Rats
            {
                do
                {
                    cout << "How many would would like to buy?";
                    cin >> Quantity;

                }while (Quantity < 0 || Money < Quantity*RATCOST);

                    LabRats += Quantity;                                              ///also equals LabRats + quantity
                    Money -= Quantity * RATCOST;
            }
            else if (StoreChoice==2)///Buy DNA
            {
                do
                {
                cout << "How many would would like to buy?";
                cin >> Quantity;

                }while (Quantity < 0 || Money < Quantity*DNACOST);

                    DNA += Quantity;                                              ///also equals LabRats + quantity
                    Money -= Quantity * DNACOST;
            }

            else if (StoreChoice ==3)///Buy Chemical
            {
                do
                {
                cout << "How many would would like to buy?";
                cin >> Quantity;

                }while (Quantity < 0 || Money < Quantity*CHEMICALCOST);

                        Chemical += Quantity;                                              ///also equals LabRats + quantity
                        Money -= Quantity * CHEMICALCOST;
            }

        }while (StoreChoice != 0);
}

    else if (MainMenuChoice == 2)///Start the Day
    {
        Days += 1;

        NewRatAmount =rand()%(NewRatamountmax-NewRatamountmin+1)+NewRatamountmin; ///Randomly generating the least number of rats, DNA, Chemical suggested for research today
        NewDNAAmount =rand()%(NewDNAamountmax-NewChemicalamountmin+1)+NewChemicalamountmin;
        NewChemicalAmount =rand()%(NewChemicalamountmax-NewChemicalamountmin+1)+NewChemicalamountmin;

        if(Location==1)///Canada
        {
            Money += CanadaDonation;
        }
        else if (Location == 2) ///China
        {
            Money += ChinaDonation;
        }
        else if (Location ==3)///United States
        {
            Money += UnitedStatesDonation;
        }

        if (MediaExposure == false) ///determining if we have the MediaExposure Upgrade
            Money +=0;
        else
            Money += Money*1.5;


        int numberOfScientists= rand()%(scientistmax-scientistmin+1)+scientistmin; ///Randomly generating the number of scientists
        cout<<"\nThe number of scientists avalible for inspection today is: " << numberOfScientists << endl;

        if (DedicatedScientist == false) /// Determining if we have the Dedicated Scientist Upgrade
            numberOfScientists += 0;
        else
            numberOfScientists += 3;

            if (LabRats >= NewRatAmount && DNA >= NewDNAAmount && Chemical >= NewDNAAmount && numberOfScientists > 5) ///now there is a potential to obtain a research point
            {
                ResearchPointPercentage = rand()%(max-min+1)+min;
                    if (ResearchPointPercentage > 30)
                    {
                        LabRats -= NewRatAmount;
                        DNA -= NewDNAAmount;
                        Chemical -= NewChemicalAmount;
                        ResearchPoints += ResearchPointGain;
                        Money -= 50000;
                        cout << "You and your team were able to generate one reserach point today. Congrats!\n" << endl;
                        system("pause");
                        system ("cls");

                    }
                    else
                    {
                        LabRats-= NewRatAmount;
                        DNA -= NewDNAAmount;
                        Chemical -= NewChemicalAmount;
                        Money -= 50000;
                        ResearchPoints += 0;
                        cout << "You and your team were not able to generate a reasearch point today\n" << endl;
                        system("pause");
                        system ("cls");
                    }
                }
        else
            {
                cout << "\t" << endl;
                if (LabRats >= NewRatAmount && DNA >= NewDNAAmount && Chemical >= NewDNAAmount && Money >= 29950) ///if you have more than 250, 200, and 200 of Rats, DNA, and Chemicals, it will be deducted, if you don't, none will be deducted
                {LabRats -= 250;
                DNA -= 200;
                Chemical -= 200;
                Money -= 50000;
                }
                cout << "You don't have enough resources or not enough scientists avalible for inspection of your product"<< endl;
                system("pause");
                system("cls");
            }
    }

    else if (MainMenuChoice == 3)///UpgradeSection

    {
        int UpgradeChoice;
            do
            {
                system ("cls");
                cout << "\tWelcome to the Covid-19 Research Effort\n";
                cout << "=================================================================" << endl;

                cout << "\tLabRats:\t" << LabRats << endl;
                cout << "\tDNA:\t\t" << DNA << endl;
                cout << "\tChemical:\t" << Chemical << endl;
                cout << "\tMoney:\t\t" << setprecision(2) << fixed << Money << endl;
                cout << "=================================================================" << endl;
                cout << "\tResearch Points:" << setprecision(1) << fixed << ResearchPoints << "\tDays:" << Days << endl;
                cout << "=================================================================" << endl;
                cout << "\tUpgrades: ";
                    if (UpgradeCount == 0)
                        cout << "\tNone" << endl;
                    if (MediaExposure == true)
                        cout <<"\tMedia Exposure\n";
                    if (DedicatedScientist == true)
                        cout << "\t\t\tDedicatedScientist\n";
                cout << "=================================================================" << endl;
                cout << "\tCurrent Location: ";
                    if (Location == 1)
                        cout << "Canada." << endl;
                    if (Location == 2)
                        cout << "China." << endl;
                    if (Location == 3)
                        cout << "United States." << endl;
                cout << "==================================================================" << endl;

                cout << "\tWelcome to the Upgrade Centre: " << endl;
                cout << "==================================================================" << endl;
                cout << "\t0.Exit the store.\n";
                cout << "\t1. Invest in Media Exposure: $1600000\n";
                cout << "\t2. Hire a Dedicated Scientist: $1600000\n";
                cin  >> UpgradeChoice;

                if (UpgradeChoice == 1 && MediaExposure == false)
                {
                     if(Money >= MediaExposureCost)
                    {
                         Money -= MediaExposureCost;
                         MediaExposure = true;
                         UpgradeCount ++;
                    }
                    else
                    {
                         cout << "You cannot afford this upgrade" << endl;
                         system("pause");
                    }

                }
                else if (UpgradeChoice == 2 && DedicatedScientist == false)
                {
                    if(Money >= DedicatedScientistCost)
                    {
                        Money -= DedicatedScientistCost;
                        DedicatedScientist = true;
                        UpgradeCount ++;
                    }
                    else
                    {
                        cout << "You cannot afford this upgrade" << endl;
                        system("pause");
                    }
                }
                else if ( UpgradeChoice == 1 && MediaExposure == true)
                    {
                        cout << "You already have this upgrade" << endl;
                        system ("pause");

                    }
                else if (UpgradeChoice ==2 && DedicatedScientist == true)
                    {
                        cout << "You already have this upgrade" << endl;
                        system ("pause");
                    }

            }while(UpgradeChoice != 0);
        }

     else if (MainMenuChoice == 4)///Crisis Analyzation Menu
    {
            system ("cls");
            cout << "\tWelcome to the Covid-19 Research Effort\n";
            cout << "=================================================================" << endl;

            cout << "\tLabRats:\t" << LabRats << endl;
            cout << "\tDNA:\t\t" << DNA << endl;
            cout << "\tChemical:\t" << Chemical << endl;
            cout << "\tMoney:\t\t" << setprecision(2) << fixed << Money << endl;
            cout << "=================================================================" << endl;
            cout << "\tResearch Points:\t" << setprecision(1) << fixed << ResearchPoints << "\tDays:" << Days << endl;
            cout << "=================================================================" << endl;
            cout << "\tUpgrades: ";
            if (UpgradeCount == 0)
                cout << "\tNone" << endl;
            if (MediaExposure == true)
                cout <<"\tMedia Exposure\n";
            if (DedicatedScientist == true)
                cout << "\t\t\tDedicatedScientist\n";
            cout << "=================================================================" << endl;
            cout << "\tCurrent Location: ";
            if (Location == 1)
                cout << "Canada." << endl;
            if (Location == 2)
                cout << "China." << endl;
            if (Location ==3)
                cout << "United States." << endl;
            cout << "=================================================================" << endl;
            cout << "Using the latest information avalible on the pandemic, your research team recommends having at least\n" << endl;
            cout << "\t" << NewRatAmount << " rats for research today\n" << endl;
            cout << "\t" << NewDNAAmount << " DNA for research today\n"<< endl;
            cout << "\t" << NewChemicalAmount << " Chemical for research today\n" << endl;
            system ("pause");
 }
    else if (MainMenuChoice == 5)///Chaning Locations
    {
       int NewLocation = 0;
        do
        {
            system ("cls");
            cout << "Current Location: ";
            if (Location == 1)
                cout << "Canada" << endl;

            if (Location == 2)
                cout << "China" << endl;
            if (Location == 3)
                cout << "United States" << endl;

            cout << "Where Would You Like To Move Your Labratory?:" << endl;
            cout << "===============================================" << endl;
            cout << "\t 1. Canada." << endl;
            cout << "\t 2. China." << endl;
            cout << "\t 3. United states." << endl;
            cin >> NewLocation;

        }while (NewLocation < 0 || NewLocation > 3);
        if (LabRats >= 200 && DNA >= 250 && Chemical >= 250 && Money >= 1000000)
            {
            Location = NewLocation;
            LabRats -=200;
            DNA -=250;
            Chemical -= 250;
            Money -=1000000;
            }
        else
        {
            cout << "You need 200 Lab rats, 250 DNA, 250 Chemicals, and $1000000 to change locations"<< endl;
            system("pause");
        }

    }

    else if (MainMenuChoice == 12345)///cheatcode
    {
        LabRats += 1000;
        DNA += 1000;
        Chemical += 1500;
        Money += 200000000;
    }
    else if (MainMenuChoice == 54321)///cheatcode
    {
        Days = 100;
        ResearchPoints = 52;
    }

if (Days ==100 && ResearchPoints < 60)///jugdges whether or not you beat the game by the end of 100 days
    {
        system("cls");
        cout<< "You were not able to find a cure in time. Game over" << endl;
        system("pause");
        return 0;
    }
    else if (ResearchPoints == 60 && Days <= 100)
    {
        system("cls");
        cout << "Congrats! You saved the world! You are a hero!" << endl;
        system("pause");
        return 0;
    }


}   while(MainMenuChoice != 0);


    return 0;
}

