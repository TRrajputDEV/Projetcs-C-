#include <iostream>
#include <vector>
#include <string>

class Todo
{
public:
    int id;
    std::string task;
    bool completed;

    Todo() : id(0), task(""), completed(false) {}
    Todo(int id, const std::string &task) : id(id), task(task), completed(false) {}
};

class TodoList
{
private:
    std::vector<Todo> todos;
    int nextId;

public:
    TodoList() : nextId(1) {}

    void addTodo()
    {
        std::string task;
        std::cout << "Enter task: ";
        std::getline(std::cin, task);
        todos.push_back(Todo{nextId++, task});
        std::cout << "Task added successfully.\n";
    }

    void listTodos()
    {
        if (todos.empty())
        {
            std::cout << "No tasks in the list.\n";
            return;
        }
        std::cout << "To-do List:\n";
        for (const auto &todo : todos)
        {
            std::cout << todo.id << ". " << todo.task << " ["
                      << (todo.completed ? "Completed" : "Incomplete") << "]\n";
        }
    }

    void updateTodo()
    {
        int id;
        std::cout << "Enter task ID to update: ";
        std::cin >> id;
        std::cin.ignore();

        for (auto &todo : todos)
        {
            if (todo.id == id)
            {
                std::cout << "Enter new task: ";
                std::getline(std::cin, todo.task);
                std::cout << "Task updated successfully.\n";
                return;
            }
        }
        std::cout << "Task not found.\n";
    }

    void deleteTodo()
    {
        int id;
        std::cout << "Enter task ID to delete: ";
        std::cin >> id;
        std::cin.ignore();

        for (auto it = todos.begin(); it != todos.end(); ++it)
        {
            if (it->id == id)
            {
                todos.erase(it);
                std::cout << "Task deleted successfully.\n";
                return;
            }
        }
        std::cout << "Task not found.\n";
    }

    void markComplete()
    {
        int id;
        std::cout << "Enter task ID to mark as complete: ";
        std::cin >> id;
        std::cin.ignore();

        for (auto &todo : todos)
        {
            if (todo.id == id)
            {
                todo.completed = true;
                std::cout << "Task marked as complete.\n";
                return;
            }
        }
        std::cout << "Task not found.\n";
    }
};

int main()
{
    TodoList todoList;
    int choice;

    while (true)
    {
        std::cout << "\n1. Add Task\n2. List Tasks\n3. Update Task\n4. Delete Task\n5. Mark Task Complete\n6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline character left in the buffer

        switch (choice)
        {
        case 1:
            todoList.addTodo();
            break;
        case 2:
            todoList.listTodos();
            break;
        case 3:
            todoList.updateTodo();
            break;
        case 4:
            todoList.deleteTodo();
            break;
        case 5:
            todoList.markComplete();
            break;
        case 6:
            std::cout << "Exiting...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
