from flask import Flask, jsonify, render_template
import requests
from paho.mqtt import client as mqtt_client

broker = "192.168.197.66"
port = 1883

def connect_mqtt():
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
        else:
            print("Failed to connect, return code %d\n" % rc)

    client = mqtt_client.Client("server")
    client.on_connect = on_connect
    client.connect(broker, port)
    return client

app = Flask(__name__)
client = connect_mqtt()  # Initialize the MQTT client outside of the route functions

server_ip = "http://192.168.197.66:4000"

@app.route("/")
def home():
    return render_template("index.html")


@app.route("/nodemcu/last")
def nodemcu():
    headers = {
        'Accept': 'application/json',
        'Cache-Control': 'no-store, no-cache, must-revalidate, post-check=0, pre-check=0, max-age=0'
    }
    r = requests.get(server_ip + "/sensors", headers=headers)
    #ให้แสดงเฉพาะค่าล่าสุด
    return jsonify(r.json()[-1])

@app.route("/nodemcu/ledon")
def led_on():
    client.loop_start()
    result = client.publish("ledControl", "1")
    client.loop_stop()
    return "OK"

@app.route("/nodemcu/ledoff")
def led_off():
    client.loop_start()
    result = client.publish("ledControl", "0")
    client.loop_stop()
    return "OK"

if __name__ == "__main__":
    app.run(host='0.0.0.0', debug=True)
