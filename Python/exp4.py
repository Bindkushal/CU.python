
class BankAccount:
    def __init__(self, account_holder, balance=0):
        self.account_holder = account_holder
        self.balance = balance

    def deposit(self, amount):
        # Add amount to the balance
        if amount > 0:
            self.balance += amount
            print(f"₹{amount} deposited successfully. New balance: ₹{self.balance}")
        else:
            print("Deposit amount must be positive.")

    def withdraw(self, amount):
        # Withdraw amount from balance if there are sufficient funds
        if 0 < amount <= self.balance:
            self.balance -= amount
            print(f"₹{amount} withdrawn successfully. Remaining balance: ₹{self.balance}")
        elif amount > self.balance:
            print("Insufficient balance.")
        else:
            print("Withdrawal amount must be positive.")

    def check_balance(self):
        # Display current balance
        print(f"Account holder: {self.account_holder}")
        print(f"Current balance: ₹{self.balance}")

# Driver code
def main():
    # Create a new bank account
    name = input("Enter the account holder's name: ")
    account = BankAccount(name)

    while True:
        print("\nBanking Menu:")
        print("1. Deposit")
        print("2. Withdraw")
        print("3. Check Balance")
        print("4. Exit")

        choice = input("Choose an option: ")

        if choice == '1':
            amount = float(input("Enter amount to deposit: "))
            account.deposit(amount)
        elif choice == '2':
            amount = float(input("Enter amount to withdraw: "))
            account.withdraw(amount)
        elif choice == '3':
            account.check_balance()
        elif choice == '4':
            print("Exiting the banking system. Have a great day!")
            break
        else:
            print("Invalid option. Please try again.")

# Run the program
if __name__ == "__main__":
    main()
