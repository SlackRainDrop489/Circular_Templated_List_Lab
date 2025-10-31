//
// Created by Christopher Vaughn on 10/24/25.
//

#ifndef CIRCULARTEMPLATEDLIST_LINKEDLIST_H
#define CIRCULARTEMPLATEDLIST_LINKEDLIST_H

#include "Media.h"
#include <iostream>

template<typename T>
struct Node {
	T data;
	Node<T> *next;

	// Constructor initializes data and pointer
	Node(T d) : data(d), next(nullptr) {
	}
};

// === 5. Hard-coded LinkedList Class (Singly, Non-Circular) ===
// This list is only capable of managing Media* objects (Song*, Podcast*, etc.) and is forward-only.
template<typename T>
class LinkedList {
	private:
		Node<T> *head;
		Node<T> *tail; // For efficient circular insertion
		Node<T> *current_play_node; // To track the currently playing item

	public:
		// Constructor: Initializes an empty list
		LinkedList() : head(nullptr), tail(nullptr), current_play_node(nullptr) {
		}

		// Destructor: Cleans up all nodes and the Media objects they point to.
		~LinkedList() {
			if (head == nullptr) {
				std::cout << "\n[Playlist cleanup complete. All memory deallocated.]" << std::endl;
				return;
			}
			Node<T> *current = head;
			Node<T> *next_node = nullptr;

			// Traverse the circular list until we get back to the start
			do {
				next_node = current->next;

				// Delete the Media object stored in the node's data pointer (polymorphic deletion)
				delete current->data;
				// Delete the node itself
				delete current;
				current = next_node;
			} while (current != head);

			head = nullptr; // Ensure head is reset
			tail = nullptr;
			std::cout << "\n[Playlist cleanup complete. All memory deallocated.]" << std::endl;
		}

		// Insertion: Adds a new item to the end of the circular list.
		void insert(T newItem) {
			Node<T> *newNode = new Node<T>(newItem);

			if (head == nullptr) {
				// Case 1: List is empty. New node is head and tail, and points to itself.
				head = newNode;
				tail = newNode;
				newNode->next = head;
				current_play_node = head; // First item is the current one
			} else {
				// Case 2: List is not empty.
				// New node's next points to the current head.
				newNode->next = head;
				// The old tail's next now points to the new node.
				tail->next = newNode;
				// The new node becomes the new tail.
				tail = newNode;
			}
		}

		// Traversal: Displays all media items in the list.
		void displayList() const {
			if (head == nullptr) {
				std::cout << "\n[Playlist is empty.]" << std::endl;
				return;
			}

			std::cout << "\n--- Current Playlist ---" << std::endl;
			Node<T> *current = head;
			int index = 1;
			do {
				// Polymorphism in action: calls the specific toString() method for Song or Podcast
				std::cout << index++ << ". " << current->data->toString() << std::endl;
				current = current->next;
			} while (current != head);
			std::cout << "------------------------" << std::endl;
		}

		// Simple play method for demonstration (students will expand this later)
		void playCurrent() const {
			if (current_play_node != nullptr) {
				std::cout << "Now Playing: ";
				current_play_node->data->play(); // Calls the virtual play() method
			} else if (head != nullptr) {
				std::cout << "Now Playing: ";
				head->data->play();
			} else {
				std::cout << "[Playlist is empty. Nothing to play.]" << std::endl;
			}
		}

		void playNext() {
			current_play_node = current_play_node->next;
			std::cout << "Next up: " << current_play_node->data->toString() << std::endl;
		}
};

#endif //CIRCULARTEMPLATEDLIST_LINKEDLIST_H
