#pragma once
#include "Employee.h"

struct Node {
public:
	Employee emp;
	Node* next;
	Node* prev;

	Node() :emp(), next(NULL), prev(NULL) {
	}
};

class DoublyList {
	Node* head, * cursor;
	int size;

public:
	DoublyList() :head(NULL), cursor(NULL), size(0) {
	}

	int getSize()const {
		return size;
	}

	Node* getHead()const {
		return head;
	}

	void Insert(const Employee& emp) {
		Node* temp = new Node;
		temp->emp = emp;
		size++;

		if (head == NULL) {
			head = temp;
			cursor = temp;
		}

		else {
			cursor = head;
			while (cursor->next != NULL) {
				Node* temp1 = cursor;
				cursor = cursor->next;
				cursor->prev = temp1;
			}

			cursor->next = temp;
			cursor->next->prev = cursor;
			cursor = temp;
		}

	}

	void remove(EmployeeID id) {
		if (head != NULL) {
			Node* temp;
			if (head->emp.getEmpID().getBatch() == id.getBatch() && head->emp.getEmpID().getRollNo() == id.getRollNo()) {
				temp = head;
				head = head->next;
				head->prev = NULL;
				delete temp;
				cursor = head;
				size--;
			}

			else {
				temp = head;
				while (temp != NULL && temp->next->emp.getEmpID().getBatch() != id.getBatch() && temp->next->emp.getEmpID().getRollNo() != id.getRollNo()) {
					temp = temp->next;
					if (temp->next == NULL) {
						temp = NULL;
					}
				}

				if (temp != NULL && temp->next->emp.getEmpID().getBatch() == id.getBatch() && temp->next->emp.getEmpID().getRollNo() == id.getRollNo()) {
					Node* temp1 = temp->next;
					cursor = temp;
					temp->next = temp->next->next;
					if (cursor->next != NULL) {
						cursor->next->prev = cursor;
					}
					delete temp1;
					size--;
				}
			}
		}
	}

	void updateSalary(const int& salary, EmployeeID id) {
		if (head != NULL) {
			if (head->emp.getEmpID().getBatch() == id.getBatch() && head->emp.getEmpID().getRollNo() == id.getRollNo()) {
				head->emp.setSalary(salary);
			}

			else {
				Node* temp = head;
				while (temp != NULL && temp->next->emp.getEmpID().getBatch() != id.getBatch() && temp->next->emp.getEmpID().getRollNo() != id.getRollNo()) {
					temp = temp->next;
					if (temp->next == NULL) {
						temp = NULL;
					}
				}

				if (temp != NULL && temp->next->emp.getEmpID().getBatch() == id.getBatch() && temp->next->emp.getEmpID().getRollNo() == id.getRollNo()) {
					temp->next->emp.setSalary(salary);
				}
			}
		}
	}

	void updateBonus(const int& bonus, EmployeeID id) {
		if (head != NULL) {
			if (head->emp.getEmpID().getBatch() == id.getBatch() && head->emp.getEmpID().getRollNo() == id.getRollNo()) {
				head->emp.setBonus(bonus);
			}

			else {
				Node* temp = head;
				while (temp != NULL && temp->next->emp.getEmpID().getBatch() != id.getBatch() && temp->next->emp.getEmpID().getRollNo() != id.getRollNo()) {
					temp = temp->next;
					if (temp->next == NULL) {
						temp = NULL;
					}
				}

				if (temp != NULL && temp->next->emp.getEmpID().getBatch() == id.getBatch() && temp->next->emp.getEmpID().getRollNo() == id.getRollNo()) {
					temp->next->emp.setBonus(bonus);
				}
			}
		}
	}

	void clear() {
		Node* temp = head;

		while (temp != NULL) {
			Node* temp1 = temp;
			temp = temp->next;
			delete temp1;
		}
		head = temp;
		size = 0;
	}

	bool isEmpty() {
		if (head == NULL) {
			return true;
		}
		return false;
	}

	void Display() {
		Node* temp = head;

		while (temp != NULL) {
			temp->emp.Display();
			temp = temp->next;
		}
	}

	void sort() {
		Node* temp, * temp1;

		temp1 = head;
		temp = head;

		for (int i = 1; i < size; i++) {
			temp = head;
			for (int j = 1; j < size; j++) {
				if (temp == head) {
					if (temp->emp.getSalary() > temp->next->emp.getSalary()) {
						head->prev = head;
						head = temp->next;
						temp1 = head->next;
						head->next = temp->prev;
						temp->prev->next = temp1;
						temp->prev = head;
						temp = head;
						head->prev = NULL;
					}
					temp = temp->next;
				}

				else if (temp != head) {
					if (temp->next != NULL) {
						if (temp->emp.getSalary() > temp->next->emp.getSalary()) {
							temp1 = temp->next;
							temp->next = temp->next->next;
							temp1->next = temp;
							temp->prev->next = temp1;
							temp->prev = temp1;
						}

						else {
							temp = temp->next;
						}
					}
				}
			}
		}
	}
};