import tkinter as tk
from tkinter import ttk

class TaskPlannerApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Task Planner")

        self.tree = ttk.Treeview(self.root, columns=('Task', 'Deadline'))
        self.tree.heading('#0', text='ID')
        self.tree.heading('Task', text='Task')
        self.tree.heading('Deadline', text='Deadline')
        self.tree.column('#0', width=50)
        self.tree.column('Task', width=200)
        self.tree.column('Deadline', width=100)
        self.tree.pack(expand=True, fill=tk.BOTH)

        self.add_button = ttk.Button(self.root, text="Add Task", command=self.add_task)
        self.add_button.pack(pady=10)

    def add_task(self):
        task_name = tk.simpledialog.askstring("Add Task", "Enter task name:")
        if task_name:
            deadline = tk.simpledialog.askstring("Add Task", "Enter deadline (YYYY-MM-DD):")
            self.tree.insert('', 'end', text='', values=(task_name, deadline))

def main():
    root = tk.Tk()
    app = TaskPlannerApp(root)
    root.mainloop()

if __name__ == "__main__":
    main()
