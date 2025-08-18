🍃 CI/CD Pipeline for Cardamom Price Scraping 🍃
📖 Project Overview

Welcome to the Cardamom Price Scraper project! This repository demonstrates the use of CI/CD pipelines on GitHub Actions to automate the process of scraping daily cardamom price data from an Indian government-backed spice website. The data is saved as a JSON file, which is then displayed in a simple web front-end.

🌟 Key Features:

Automated Data Scraping: Scrapes cardamom prices daily from a government-backed Indian spice website.

CI/CD Pipeline: The build and scraping process is automated using GitHub Actions, triggered every day at 10:00 AM UTC.

JSON Data Storage: Scraped data is stored in a JSON file, which is pushed to the repository.

Web Front-End: Displays the scraped data in a pretty-printed format for easy viewing.

🔗 Cardamom Price Source

The cardamom price data is fetched from a government-verified Indian Spice website, which is updated daily with new market prices.

You can view the website at:
Indian Spice Price Website


🛠️ Getting Started

To get this project up and running locally, follow these steps:

🔧 Prerequisites

GitHub account and repository access.

C++ development tools:

g++, libcurl, and nlohmann-json3-dev libraries.

📥 Installation

Clone the repository:

git clone https://github.com/yourusername/ci-cd-cardamom-prices.git


Navigate to the project folder:

cd ci-cd-cardamom-prices


Install necessary dependencies (For Ubuntu):

sudo apt-get update
sudo apt-get install -y g++ libcurl4-openssl-dev nlohmann-json3-dev

🚀 Running the Program Locally

If you want to test the scraping process and run the program locally, follow these steps:

Build the C++ project:

g++ main.cpp HtmlResponds.cpp DeepCleaner.cpp -o run -lcurl


Run the program:

./run


This will scrape the price data from the website and store it in the cardamom_data.json file.

🌍 Viewing the Data

To view the scraped data in a browser:

Open the frontend/index.html file.

The page will display the contents of the cardamom_data.json file in a clean, pretty-printed format.

🛠️ CI/CD Pipeline
📅 Daily Automated Build & Scraping

This project uses GitHub Actions to automate the build and data scraping process. Every day at 10:00 AM UTC, the pipeline is triggered to:

Build the C++ project.

Run the program to scrape the cardamom price data.

Commit and Push the updated cardamom_data.json file to the repository.

The CI/CD pipeline configuration is located in .github/workflows/pipeline.yml.

💻 Front-End Display

The frontend/ folder contains a simple HTML page (index.html) that uses JavaScript to fetch and display the cardamom price data from the cardamom_data.json file.

The data is shown in a pretty-printed format to make it easy for users to read and interpret.
