<h1 align="center">🍃 CI/CD Pipeline for Cardamom Price Scraping 🍃</h1>

<p align="center">
  <a href="https://github.com/yourusername/ci-cd-cardamom-prices" target="_blank">
    <img src="https://img.shields.io/github/stars/yourusername/ci-cd-cardamom-prices?style=social" alt="GitHub Stars"/>
  </a>
  <a href="https://github.com/yourusername/ci-cd-cardamom-prices" target="_blank">
    <img src="https://img.shields.io/github/forks/yourusername/ci-cd-cardamom-prices?style=social" alt="GitHub Forks"/>
  </a>
</p>

<hr />

<h2 align="center">📖 Project Overview</h2>

<p align="center">
  <img src="https://via.placeholder.com/800x400/2d2d2d/ffffff?text=Cardamom+Price+Scraper" alt="Project Image"/>
</p>

<p align="center">
  Welcome to the <strong>Cardamom Price Scraper</strong> project! This repository demonstrates the use of <strong>CI/CD pipelines</strong> on <strong>GitHub Actions</strong> to automate the process of scraping <strong>daily cardamom price data</strong> from an <em>Indian government-backed spice website</em>. The data is saved as a <strong>JSON file</strong>, which is then displayed in a simple <strong>web front-end</strong>.
</p>

<h3 align="center">🌟 Key Features</h3>
<ul>
  <li><strong>Automated Data Scraping</strong>: Scrapes cardamom prices daily from a government-backed Indian spice website.</li>
  <li><strong>CI/CD Pipeline</strong>: The build and scraping process is automated using GitHub Actions, triggered every day at <strong>10:00 AM UTC</strong>.</li>
  <li><strong>JSON Data Storage</strong>: Scraped data is stored in a JSON file, which is pushed to the repository.</li>
  <li><strong>Web Front-End</strong>: Displays the scraped data in a pretty-printed format for easy viewing.</li>
</ul>

<hr />

<h2 align="center">🔗 Cardamom Price Source</h2>

<p align="center">
  The cardamom price data is fetched from a <strong>government-verified Indian Spice website</strong>, which is updated daily with new market prices.
</p>

<p align="center">
  <a href="https://www.indianspiceprices.gov.in" target="_blank">
    Visit the Indian Spice Price Website
  </a>
</p>

<p align="center">
  *(Replace with the actual URL of the website you're scraping.)*
</p>

<hr />


<hr />

<h2 align="center">🛠️ Getting Started</h2>

<h3>🔧 Prerequisites</h3>
<p>Before you start, make sure you have the following installed:</p>
<ul>
  <li><strong>GitHub account</strong> and repository access.</li>
  <li><strong>C++ development tools</strong>:
    <ul>
      <li><code>g++</code>, <code>libcurl</code>, and <code>nlohmann-json3-dev</code> libraries.</li>
    </ul>
  </li>
</ul>

<h3>📥 Installation</h3>

<pre>
1. Clone the repository:
   <code>git clone https://github.com/yourusername/ci-cd-cardamom-prices.git</code>

2. Navigate to the project folder:
   <code>cd ci-cd-cardamom-prices</code>

3. Install necessary dependencies (For Ubuntu):
   <code>sudo apt-get update && sudo apt-get install -y g++ libcurl4-openssl-dev nlohmann-json3-dev</code>
</pre>

<hr />

<h2 align="center">🚀 Running the Program Locally</h2>

<p>If you want to test the scraping process and run the program locally, follow these steps:</p>

<pre>
1. Build the C++ project:
   <code>g++ main.cpp HtmlResponds.cpp DeepCleaner.cpp -o run -lcurl</code>

2. Run the program:
   <code>./run</code>

This will scrape the price data from the website and store it in the <code>cardamom_data.json</code> file.
</pre>

<hr />

<h2 align="center">🌍 Viewing the Data</h2>

<p>To view the scraped data in a browser:</p>
<ol>
  <li>Open the <code>frontend/index.html</code> file.</li>
  <li>The page will display the contents of the <code>cardamom_data.json</code> file in a clean, <strong>pretty-printed</strong> format.</li>
</ol>

<hr />

<h2 align="center">🛠️ CI/CD Pipeline</h2>

<h3>📅 Daily Automated Build & Scraping</h3>

<p>This project uses <strong>GitHub Actions</strong> to automate the build and data scraping process. Every day at <strong>10:00 AM UTC</strong>, the pipeline is triggered to:</p>
<ul>
  <li><strong>Build</strong> the C++ project.</li>
  <li><strong>Run</strong> the program to scrape the cardamom price data.</li>
  <li><strong>Commit and Push</strong> the updated <code>cardamom_data.json</code> file to the repository.</li>
</ul>

<p>The CI/CD pipeline configuration is located in <code>.github/workflows/pipeline.yml</code>.</p>

<hr />

<h2 align="center">💻 Front-End Display</h2>

<p>The <strong>frontend/</strong> folder contains a simple <strong>HTML page</strong> (<code>index.html</code>) that uses JavaScript to fetch and display the <strong>cardamom price data</strong> from the <code>cardamom_data.json</code> file.</p>

<p>The data is shown in a <strong>pretty-printed</strong> format to make it easy for users to read and interpret.</p>

<hr />

<h2 align="center">⚙️ Conclusion</h2>

<p>This project showcases a complete CI/CD workflow using <strong>GitHub Actions</strong> to automate the scraping of cardamom prices and manage them in a JSON file. The front-end then displays this data in a user-friendly format.</p>

<p>By combining <strong>C++</strong>, <strong>GitHub Actions</strong>, and a simple web interface, this project provides an easy way to stay updated with cardamom market prices, fully automated and displayed on a webpage.</p>

<hr />

<h2 align="center">📜 License</h2>

<p>This project is licensed under the MIT License – see the <a href="LICENSE">LICENSE</a> file for details.</p>

---

