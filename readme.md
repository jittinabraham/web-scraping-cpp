CI/CD Pipeline for Cardamom Price Scraping
Overview

Welcome to the Cardamom Price Scraper project! This is a basic implementation of CI/CD pipelines using GitHub Actions, built to automatically scrape the daily cardamom price data from an Indian Spice website, process it, and store the information as a JSON file. The project uses C++ to fetch and process the data, and a simple web front-end to display the data in a user-friendly format.

Every day at 10:00 AM UTC, the GitHub Actions CI/CD pipeline is triggered to:

Build the project.

Run the scraping program.

Update the price data in a JSON file.

The front-end displays the scraped data in a pretty-printed format, providing an easy way to view the latest cardamom prices.

Key Features

Automated Data Scraping: Scrapes cardamom prices from an Indian government-backed spice website, which updates daily.

CI/CD Pipeline: GitHub Actions automates the entire process, running the build and scraping operations daily at 10:00 AM UTC.

JSON Data Storage: The scraped price data is stored in a JSON file, which is then pushed to the repository.

Web Front-End: Displays the JSON data in a clean, readable format for users to easily view the latest prices.

Cardamom Price Source

The price information is scraped from an Indian Spice website that provides updated market prices for various spices, including cardamom. The website is updated regularly by the government, ensuring the price data is accurate and current.

You can visit the website at Indian Spice Price (Note: Replace with the actual URL of the website you're scraping).


Getting Started
Prerequisites

Before you start, make sure you have the following installed:

GitHub account and access to the repository.

C++ development tools:

g++, libcurl, and nlohmann-json3-dev dependencies for building and running the C++ program.

Installation

Clone the repository:

git clone https://github.com/yourusername/ci-cd-cardamom-prices.git


Navigate into the project folder:

cd ci-cd-cardamom-prices


Install necessary dependencies (for Ubuntu):

sudo apt-get update
sudo apt-get install -y g++ libcurl4-openssl-dev nlohmann-json3-dev

Running the Program Locally

To run the program locally and scrape the cardamom price data:

Build the C++ project:

g++ main.cpp HtmlResponds.cpp DeepCleaner.cpp -o run -lcurl


Run the program:

./run


This will scrape the price data and save it in the cardamom_data.json file.

Viewing the Data

Open the frontend/index.html file in your browser.

The webpage will display the contents of cardamom_data.json in a user-friendly, pretty-printed format.

CI/CD Pipeline

This project leverages GitHub Actions to automate the build, scraping, and updating process. The pipeline is configured to:

Build the C++ project.

Run the scraping program at 10:00 AM UTC daily.

Commit and push the updated cardamom_data.json file back to the repository.

GitHub Actions Workflow

The pipeline configuration is located in .github/workflows/pipeline.yml, and it runs as follows:

Scheduled Execution: The pipeline is triggered every day at 10:00 AM UTC using a cron job.

Build and Run: The C++ project is compiled, and the program is executed to scrape the price data.

Commit and Push: After scraping, the updated cardamom_data.json is committed and pushed to the repository.

You can monitor the status of the CI/CD pipeline from the Actions tab of the GitHub repository.

Front-End Display

The frontend/ folder contains a simple HTML page (index.html) that uses JavaScript to fetch and display the cardamom price data from the cardamom_data.json file.

The data is displayed in a pretty-printed format for easy reading.
