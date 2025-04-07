# from: Sebastian Raschka: Build a Large Language Model, Manning, 2025

import os
import urllib.request

if not os.path.exists("the-verdict.txt"):
    url = ("https://raw.githubusercontent.com/rasbt/"
           "LLMs-from-scratch/main/ch02/01_main-chapter-code/"
           "the-verdict.txt")
    file_path = "the-verdict.txt"
    urllib.request.urlretrieve(url, file_path)
    print("✅ the-verdict.txt downloaded successfully.")
else:
    print("ℹ️ the-verdict.txt already exists.")
