import json

def print_vector_as_json(vec):
    output_json = json.dumps(vec)
    print(output_json)

def print_quoted_string(string):
    print(f'"{string}"')

if __name__ == "__main__":
    vector = [1, 2, 3, 4]
    print_vector_as_json(vector)

    quoted_str = "hello"
    print_quoted_string(quoted_str)