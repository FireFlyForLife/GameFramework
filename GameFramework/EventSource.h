#pragma once
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

template<typename... P>
class EventSource {
public:
	using callbackType = std::function<void(P...)>;

	int add(const callbackType& handler) {
		listeners.insert(std::pair<int, callbackType>( index, handler ));
		return index++;
	}

	bool remove(int id) {
		auto it = listeners.find(id);
		if (it != listeners.end()) {
			callbackType callback = it->second;
			listeners.erase(it);
			return true;
		}

		return false;
	}

	void call(P&& ... params) {
		for each (auto handler_pair in listeners)
		{
			handler_pair.second(std::forward<P>(params)...);
		}
	}

	EventSource& operator+=(const callbackType& handler) { //this can't return a id, not a good idea :/
		this->add(handler);
		return *this;
	}
	EventSource& operator-=(const callbackType& handler) { 
		//this->remove(handler); <==== this is the reason operator overloading doesn't work, I cant compare std:function's so i cant remove the correct listener
		return *this;
	}
protected:
	std::map<int, callbackType> listeners;
	int index = 0;
};
