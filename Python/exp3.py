# Basic file operations in Python: Read, Write, Append

# Writing to a file
def write_to_file(file_name, content):
    with open(file_name, 'w') as file:
        file.write(content)
    print(f"Content written to {file_name}")

# Reading from a file
def read_from_file(file_name):
    try:
        with open(file_name, 'r') as file:
            content = file.read()
        print(f"Content of {file_name}:")
        print(content)
    except FileNotFoundError:
        print(f"{file_name} not found.")

# Appending to a file
def append_to_file(file_name, content):
    with open(file_name, 'a') as file:
        file.write(content)
    print(f"Content appended to {file_name}")

# Example usage:
if __name__ == "__main__":
    file_name = "sample.txt"

    # Write to the file
    write_to_file(file_name, "This is the first line.\n")

    # Append to the file
    append_to_file(file_name, "This is the appended line.\n")

    # Read from the file
    read_from_file(file_name)
