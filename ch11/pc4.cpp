//Nick Zimanski - CIS264
//29 August 2020

#include <iostream>
using namespace std;
const int NUM_MONTHS = 12;
struct WeatherData {
    int totalRainfall;
    int highTemp;
    int lowTemp;
    double avgTemp;
};
void getWeatherData(WeatherData& w, int x) {
    do {
        cout << "Please enter the total rainfall for month " << x + 1 << ": ";
        cin >> w.totalRainfall;
    } while (w.totalRainfall < 0);

    do {
        cout << "Please enter the highest temperature for month " << x+1 << ": ";
        cin >> w.highTemp;
    } while(w.highTemp < -100 || w.highTemp > 140);

    do {
        cout << "Please enter the lowest temperature for month " << x+1 << ": ";
        cin >> w.lowTemp;
    } while(w.lowTemp < -100 || w.lowTemp > 140 || w.lowTemp > w.highTemp);

    w.avgTemp = ((double)w.lowTemp + (double)w.highTemp) / 2;
}
void displayWeatherData(WeatherData w[]) {
    int high = INT_MIN, low = INT_MAX, totalRain = 0, totalTemp = 0, hm, lm;
    double avgRain, avgTemp;
    for (int i = 0; i < NUM_MONTHS; i++) {
        if (w[i].highTemp > high) {high = w[i].highTemp;hm = i;}
        if (w[i].lowTemp < low) {low = w[i].lowTemp;lm=i;}
        totalRain += w[i].totalRainfall;
        totalTemp += w[i].avgTemp;
    }
    avgRain = (double)totalRain/NUM_MONTHS;
    avgTemp = (double)totalTemp/NUM_MONTHS;
    cout << "\n\nAverage Monthly rainfall: " << avgRain << " inches.\n";
    cout << "Total rainfall for the year: "<< totalRain << " inches.\n";
    cout << "Highest temperature of the year was " << high << " degrees in month " << hm+1 << ".\n";
    cout << "Lowest temperature of the year was " << low << " degrees in month " << lm+1 << ".\n";
    cout << "Average monthly temperature was " << avgTemp << " degrees.";
}
int main() {
    WeatherData months[NUM_MONTHS];

    for (int i = 0; i < NUM_MONTHS; i++) {
        getWeatherData(months[i], i);
    }
    displayWeatherData(months);
    return 0;
}