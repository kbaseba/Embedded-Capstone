import os
import boto3
from dotenv import load_dotenv

load_dotenv()  # take environment variables from .env.

ACCESS_KEY_ID = os.getenv('ACCESS_KEY_ID')
SECRET_ACCESS_KEY = os.getenv('SECRET_ACCESS_KEY')

test_image = "/Users/rahul/Embedded-Capstone/src/ml-utils/image-label-detector/test/hot-air-balloon.jpeg"

client = boto3.client('rekognition', 
                       aws_access_key_id = ACCESS_KEY_ID,
                       aws_secret_access_key = SECRET_ACCESS_KEY)

with open(test_image, 'rb') as source_image:
    source_bytes = source_image.read()

response = client.detect_labels(Image = {'Bytes': source_bytes},
                                MaxLabels = 2)

print(response)