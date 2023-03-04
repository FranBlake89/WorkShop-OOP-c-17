
/*
Name: Francisco Castillo
Course: OOP
Section: NDD
Seneca ID: 148904212
Date: 2023-mm-dd
*/

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H

#include <string>

namespace sdds {
	template<typename T>
	class Collection {
		std::string m_name{};
		T* m_arr{};
		size_t m_arraySize{};
		void (*observer)(const Collection<T>&, const T&) {
			nullptr
		};

	public:
		Collection(const std::string& name) {
			m_name = name;
		}
		Collection(const Collection& V) = delete;
		Collection& operator=(const Collection& V) = delete;
		virtual ~Collection() {
			delete[] m_arr;
			m_arr = nullptr;
		};
		const std::string& name() const {
			return m_name;
		};
		size_t size() const {
			return m_arraySize;
		};
		void setObserver(void (*observer)(const Collection<T>&, const T&)) {
			this->observer = observer;
		};
		Collection<T>& operator+=(const T& item) {
			bool found = false;
			for (size_t i = 0u; i < m_arraySize; i++) {
				if (m_arr[i].title() == item.title())
					found = true;
			}
			if (!found) {
				T* temp = new T[m_arraySize + 1];
				for (size_t i = 0u; i < m_arraySize; i++) {
					temp[i] = m_arr[i];
				}
				temp[m_arraySize] = item;
				m_arraySize++;

				delete[] m_arr;
				m_arr = nullptr;

				m_arr = new T[m_arraySize];
				for (size_t i = 0u; i < m_arraySize; i++) {
					m_arr[i] = temp[i];
				}
				delete[] temp;
				temp = nullptr;

				if (observer != nullptr)
					observer((*this), item);
			}
			return *this;
		};
		T& operator[](size_t idx) const {
			std::string err = "Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(size()) + "] items.";
			if (idx >= size())
				throw std::out_of_range(err);
			else {
				return m_arr[idx];
			}
		};

		T* operator[](const std::string title) const {
			bool found = false;
			T* ptr = nullptr;
			for (size_t i = 0u; i < m_arraySize && !found; i++) {
				if (m_arr[i].title() == title) {
					ptr = &m_arr[i];
					found = true;
				}
			}
			return ptr;
		};

		friend std::ostream& operator<<(std::ostream& ostr, const Collection& obj) {
			for (size_t i = 0u; i < obj.size(); i++) {
				ostr << obj[i];
			}
			return ostr;
		}
	};
}

#endif //!SDDS_COLLECTION_H