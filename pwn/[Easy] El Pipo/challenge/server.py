from flask import Flask, request, jsonify
import subprocess

app = Flask(__name__, static_folder='/', template_folder='templates')

@app.route('/')
def index():
    return open('templates/index.html').read()

@app.route('/process', methods=['POST'])
def process_input():
    data = request.get_json()
    user_input = data.get('userInput')

    if not user_input:
        return "Invalid input", 400

    try:
        # Call the binary and pass the input as bytes without encoding again
        result = subprocess.run(['./el_pipo'], input=user_input, capture_output=True, text=True)
        return result.stdout  # Return the captured stdout to be displayed on the webpage
    except Exception as e:
        return f"Error: {e}", 500

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=1337, debug=True)