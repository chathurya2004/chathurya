import tkinter as tk
from tkinter import messagebox
import re

class RegistrationForm:
    def __init__(self, root):
        self.root = root
        self.root.title("Registration Form")

        # Create and place widgets
        tk.Label(root, text="Username:").grid(row=0, column=0, padx=10, pady=10, sticky='e')
        self.username_entry = tk.Entry(root)
        self.username_entry.grid(row=0, column=1, padx=10, pady=10)

        tk.Label(root, text="Email:").grid(row=1, column=0, padx=10, pady=10, sticky='e')
        self.email_entry = tk.Entry(root)
        self.email_entry.grid(row=1, column=1, padx=10, pady=10)

        tk.Label(root, text="Password:").grid(row=2, column=0, padx=10, pady=10, sticky='e')
        self.password_entry = tk.Entry(root, show='*')
        self.password_entry.grid(row=2, column=1, padx=10, pady=10)

        tk.Label(root, text="Confirm Password:").grid(row=3, column=0, padx=10, pady=10, sticky='e')
        self.confirm_password_entry = tk.Entry(root, show='*')
        self.confirm_password_entry.grid(row=3, column=1, padx=10, pady=10)

        self.submit_button = tk.Button(root, text="Register", command=self.register)
        self.submit_button.grid(row=4, column=0, columnspan=2, pady=10)

    def is_valid_email(self, email):
        # Simple regex for email validation
        pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
        return re.match(pattern, email)

    def is_valid_password(self, password):
        # Basic password validation (at least 6 characters)
        return len(password) >= 6

    def register(self):
        username = self.username_entry.get().strip()
        email = self.email_entry.get().strip()
        password = self.password_entry.get().strip()
        confirm_password = self.confirm_password_entry.get().strip()

        # Validate email
        if not self.is_valid_email(email):
            messagebox.showerror("Error", "Invalid email address.")
            return

        # Validate password
        if not self.is_valid_password(password):
            messagebox.showerror("Error", "Password must be at least 6 characters long.")
            return

        # Check if passwords match
        if password != confirm_password:
            messagebox.showerror("Error", "Passwords do not match.")
            return

        # Registration successful
        messagebox.showinfo("Success", "Registration Successful!")
        self.clear_form()

    def clear_form(self):
        self.username_entry.delete(0, tk.END)
        self.email_entry.delete(0, tk.END)
        self.password_entry.delete(0, tk.END)
        self.confirm_password_entry.delete(0, tk.END)

if __name__ == "__main__":
    root = tk.Tk()
    app = RegistrationForm(root)
    root.mainloop()
