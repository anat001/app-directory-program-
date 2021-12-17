#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class googlePlayApp 
{
private:
    string appName;
    string category;
    double rating;
    int numInstalls;
    int numReviews;
    string purchasePrice;
public:
    googlePlayApp();
    void setName(string newName) { appName = newName; }
    string getName() { return appName; }; 
    void setCategory(string newCategory) { category = newCategory; }
    string getCategory() { return category; };
    void setRating(double newRating) { rating = newRating; }
    double getRating() { return rating; };
    void setnumInstalls(int newnumInstalls) { numInstalls = newnumInstalls; }
    int getnumInstalls() { return numInstalls; };
    void setnumReviews(int newnumReviews) { numReviews = newnumReviews; }
    int getnumReviews() { return numReviews; };
    void setpurchasePrice(string newpurchasePrice) { purchasePrice = newpurchasePrice; }
    string getpurchasePrice() { return purchasePrice; };
};

googlePlayApp::googlePlayApp() {
    //cout << "In the default constructor\n";
    appName = "No Name App";
    category = "None";
    rating = 0;
    numInstalls = 0;
    numReviews = 0;
    purchasePrice = "No price";
}

void readSingleApp(const string &inputLine, string &appName, string &appCategory,
                    double &appRating, int &appNumInstalls, int &appNumReviews, string &appPrice) {
    istringstream istr(inputLine);
    string fields[6];
    string tmp;
    int i = 0;
    
    while (getline(istr, tmp, ',')) {
        fields[i++] = tmp;
    }
    
    appName = fields[0];
    appCategory = fields[1];
    appRating = atof(fields[2].c_str());
    appNumInstalls = atof(fields[3].c_str());
    appNumReviews = atof(fields[4].c_str());
    appPrice = fields[5];
    appPrice.pop_back();

  }

int linearsearch (googlePlayApp apps[], int size, string userinput) {
    for(int i = 0; i < size; i++) {
        if (userinput == apps[i].getName()) {
            return i;
        }
    }
    return -1;
} 


int main () 
{
    const int SIZE = 25;
    googlePlayApp apps[SIZE];
    string userinput;
    ifstream dataFile;

    dataFile.open("allapps.csv");

    string line;
    int number = 0;

    while (getline(dataFile, line)) {

        string appName, appCategory, appPrice;
        double appRating;
        int appNumInstalls, appNumReviews;
        
        
        readSingleApp(line, appName, appCategory, appRating, appNumInstalls, appNumReviews, appPrice);

    
 
        apps[number].setName(appName);
        apps[number].setCategory(appCategory);
        apps[number].setRating(appRating);
        apps[number].setnumInstalls(appNumInstalls);
        apps[number].setnumReviews(appNumReviews);
        if (appPrice == "$0.00") {
            apps[number].setpurchasePrice("Free");
        } else {
            apps[number].setpurchasePrice(appPrice);
        }
        apps[number].setRating(appRating);

        number++;
        
    }

    cout << "Read 25 apps.\n";

    while (true) {

    cout << "Please enter an application name (X to quit): ";
    getline(cin, userinput); 
    
    

    if(userinput == "X") {
        exit(0);
        break;
    } 
   
        int i = linearsearch(apps, SIZE, userinput);
        if(i > -1) {
            cout << "\nName: " << apps[i].getName();
            cout << endl;
            cout << "Category: " << apps[i].getCategory();
            cout << endl;
            cout << "Rating: " << apps[i].getRating();
            cout << endl;
            cout << "Number of installs: " << apps[i].getnumInstalls();
            cout << endl;
            cout << "Number of reviews: " << apps[i].getnumReviews();
            cout << endl;
            cout << "Price: " << apps[i]. getpurchasePrice();
            cout << "\n\n";
        } else {
            cout << "Application not found.\n";
        }    
   
    }
       
}
