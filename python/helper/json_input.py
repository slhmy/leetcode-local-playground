import json

def read_vector_from_json_str():
    json_str = input()
    json_array = json.loads(json_str)
    return json_array

def read_quoted_string():
    str_input = input()
    if str_input.startswith('"'):
        str_input = str_input[1:]
    if str_input.endswith('"'):
        str_input = str_input[:-1]
    return str_input

if __name__ == "__main__":
    vector = read_vector_from_json_str()
    print("Parsed vector:", vector)

    quoted_str = read_quoted_string()
    print("Parsed quoted string:", quoted_str)