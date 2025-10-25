# CMPSC 272: Circular Templated Linked List Lab

## Project Overview: The Universal Playlist Manager

This project provides a working C++ command-line application—a simple **Media Player Playlist** manager. The application demonstrates core object-oriented principles by using an abstract base class (`Media`) and derived classes (`Song`, `Podcast`) to allow different media types to exist in a single list (Polymorphism).

The goal of this lab is to take the provided starter code, which implements a basic, hard-coded, singly linked list, and evolve it into a robust, generalized data structure: a **Circular Templated Linked List**.

## Starter Code Architecture

The provided repository is fully structured into separate files (`.h` and `.cpp`) and already implements the correct OOP hierarchy, setting the stage for the linked list modifications.

| Component | Files | Purpose | 
 | ----- | ----- | ----- | 
| **Base Class (Polymorphism)** | `Media.h`, `Media.cpp` | Defines the abstract interface (`play()`, `toString()`) and shared attributes (`title`, `durationSeconds`) for all media items. | 
| **Derived Classes** | `Song.h/cpp`, `Podcast.h/cpp` | Implement the specific behavior and unique attributes for each media type. | 
| **Client Code (Main)** | `main.cpp` | Contains the menu loop and client logic. It currently instantiates a hard-coded `LinkedList` of `Media*`. | 
| **Linked List (Start)** | `LinkedList.h`, `LinkedList.cpp` | **The focus of the lab.** Currently contains hard-coded `Node` and `LinkedList` structures that only accept `Media*` and function as a non-circular, singly linked list. | 

## Phase 1: Templatization

The first goal is to convert the **hard-coded** list into a **generic class template**. This makes the `LinkedList` reusable for any data type (`T`). Since the Polymorphism is already established, the goal is to make the list generic enough to accept the `Media*` pointer type as its template parameter.

### Required Changes for Phase 1:

1. Modify the `Node` structure in **`LinkedList.h`** to use `template <typename T>` and replace `Media*` with `T*` (or `T` if storing non-pointers, but in this case, `T*` is safer).

2. Modify the `LinkedList` class in **`LinkedList.h`** to use `template <typename T>`.

3. Update all member functions (`insert()`, `displayList()`, `~LinkedList()`) in **`LinkedList.h`** and **`LinkedList.cpp`** to include the appropriate template syntax.

## Phase 2: Circular Linked List

The second goal is to modify the mechanics of the list to be **circular**. Instead of terminating at a `nullptr`, the last node must link back to the first node (`head`).

### Required Changes for Phase 2:

1. **Add `tail` Pointer:** Update the `LinkedList` class definition to maintain a pointer to the last node (`tail`). This is necessary for efficient circular insertion.

2. **Circular Insertion:** Modify the `insert()` method logic to handle new nodes by linking the **new node's `next` pointer** to the **`head`**, and then making the **old tail's `next` pointer** point to the new node.

3. **Circular Traversal:** Modify `displayList()` and the destructor (`~LinkedList()`) to stop traversing when the current pointer reaches the `head` pointer (or when `current->next == head`), ensuring they don't loop infinitely.

4. **Implement `playNext()`:** Create a new method, `playNext()`, that advances a **`current`** member pointer one position. If `current` advances from the tail, it should wrap around to the head, maintaining continuous playback.

5. **Destructor Safety:** Ensure the destructor correctly identifies the termination condition for the circular list cleanup process.
