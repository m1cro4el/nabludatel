#include "WeatherData.h"

WeatherData::WeatherData() {

}

//register
void WeatherData::registerObserver(Observer* o) {
	observers.push_back(o);
}
//remove
void WeatherData::removeObserver(Observer* o) {
	auto iter = observers.begin();
	while (iter != observers.end()) {
		if (*iter == o) {
			iter = observers.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

//notify
void WeatherData::notifyObservers() {
	for (auto iter : observers) {
		((Observer*)iter)->update(temperature, humidity, pressure);
	}
}

//measurements
void WeatherData::measurementsChanged() {
	notifyObservers();
}

//setMeasurements
void WeatherData::setMeasurements(float temperature, float humidity, float pressure) {
	this->temperature = temperature;
	this->humidity = humidity;
	this->pressure = pressure;
	measurementsChanged();
}