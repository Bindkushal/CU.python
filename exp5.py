# Sample list of dictionaries
data = [
    {"name": "John", "age": 25},
    {"name": "Anna", "age": 22},
    {"name": "Mike", "age": 32},
    {"name": "Sophia", "age": 28}
]

# Function to sort list of dictionaries by a key
def sort_by_key(data, key):
    return sorted(data, key=lambda x: x[key])

# Sort by 'name'
sorted_by_name = sort_by_key(data, 'name')
print("Sorted by name:")
for item in sorted_by_name:
    print(item)

# Sort by 'age'
sorted_by_age = sort_by_key(data, 'age')
print("\nSorted by age:")
for item in sorted_by_age:
    print(item)
