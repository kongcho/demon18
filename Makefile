setup:
	python3 -m venv venv-demon
	venv-demon/bin/pip install -r requirements.txt

run:
	venv-demon/bin/python app.py
