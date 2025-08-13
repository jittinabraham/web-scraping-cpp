document.getElementById("cardamomType").addEventListener("change", function() {
    const type = this.value;
    const display = document.getElementById("priceDisplay");

    if (!type) {
        display.innerHTML = "<p>📊 Please select a cardamom type to view the latest price.</p>";
        return;
    }

    const fileName = type === "small" ? "small_cardamom.json" : "large_cardamom.json";

    fetch(fileName + "?t=" + new Date().getTime()) // avoid caching
        .then(res => res.json())
        .then(data => {
            if (!Array.isArray(data) || data.length === 0) {
                display.innerHTML = "<p>⚠ No data available in JSON.</p>";
                return;
            }

            const latest = data[data.length - 1]; // latest entry
            let html = `<h2>${latest.Spice}</h2>`;

            if (type === "small") {
                html += `
                    <p><i class="fas fa-calendar-day"></i> <strong>Date of Auction:</strong> ${latest["Date of Auction"]}</p>
                    <p><i class="fas fa-building"></i> <strong>Auctioneer:</strong> ${latest["Auctioneer"]}</p>
                    <p><i class="fas fa-boxes"></i> <strong>No. of Lots:</strong> ${latest["No.of lots"]}</p>
                    <p><i class="fas fa-truck-loading"></i> <strong>Qty Arrived:</strong> ${latest["Qty Arrived (Kgs)"]} kg</p>
                    <p><i class="fas fa-shopping-basket"></i> <strong>Qty Sold:</strong> ${latest["Qty Sold (Kgs)"]} kg</p>
                    <p><i class="fas fa-arrow-up"></i> <strong>Max Price (Rs./Kg):</strong> ₹${latest["Max Price (Rs./Kg)"]}</p>
                    <p><i class="fas fa-balance-scale"></i> <strong>Avg Price (Rs./Kg):</strong> ₹${latest["Avg. Price (Rs./Kg)"]}</p>
                `;
            } else {
                html += `
                    <p><i class="fas fa-calendar-day"></i> <strong>Date:</strong> ${latest.Date}</p>
                    <p><i class="fas fa-map-marker-alt"></i> <strong>Market:</strong> ${latest.Market}</p>
                    <p><i class="fas fa-leaf"></i> <strong>Type:</strong> ${latest.Type}</p>
                    <p><i class="fas fa-rupee-sign"></i> <strong>Price (Rs./Kg):</strong> ₹${latest["Price (Rs./Kg)"]}</p>
                `;
            }

            display.innerHTML = html;
        })
        .catch(err => {
            console.error("Error fetching JSON:", err);
            display.innerHTML = "<p>⚠ Failed to load price data.</p>";
        });
});
