document.getElementById("cardamomType").addEventListener("change", function() {
    const type = this.value;
    const display = document.getElementById("priceDisplay");

    if (!type) {
        display.innerHTML = "<p>📊 Please select a cardamom type to view the latest price.</p>";
        return;
    }

    fetch("../cardamom_data.json?t=" + new Date().getTime())
        .then(res => res.json())
        .then(data => {
            let key = type === "small" ? "spice: small cardamom" : "spice: large cardamom";

            // Filter only relevant data
            const entries = data.filter(item => item[key]);

            if (!entries.length) {
                display.innerHTML = "<p>⚠ No data available for " + key + ".</p>";
                return;
            }

            // Build only children slides
            let slides = entries.map((entry, i) => {
                const latest = entry[key];
                let html = `<div class="child-slide ${i === 0 ? 'active' : ''}">`;

                if (type === "small") {
                    html += `
                        <p><strong>Date of Auction:</strong> ${latest["date of auction"]}</p>
                        <p><strong>Auctioneer:</strong> ${latest["auctioneer"]}</p>
                        <p><strong>No. of Lots:</strong> ${latest["no.of lots"]}</p>
                        <p><strong>Qty Arrived:</strong> ${latest["qty arrived (kgs)"]} kg</p>
                        <p><strong>Qty Sold:</strong> ${latest["qty sold (kgs)"]} kg</p>
                        <p><strong>Max Price (Rs./Kg):</strong> ₹${latest["max price (rs./kg)"]}</p>
                        <p><strong>Avg Price (Rs./Kg):</strong> ₹${latest["avg. price (rs./kg)"]}</p>
                    `;
                } else {
                    html += `
                        <p><strong>Date:</strong> ${latest.date}</p>
                        <p><strong>Market:</strong> ${latest.market}</p>
                        <p><strong>Type:</strong> ${latest.type}</p>
                        <p><strong>Price (Rs./Kg):</strong> ₹${latest["price (rs./kg)"]}</p>
                    `;
                }

                html += `</div>`;
                return html;
            }).join("");

            // Build dots
            let dots = entries.map((_, i) => 
                `<span class="dot ${i === 0 ? 'active' : ''}" data-index="${i}"></span>`
            ).join("");

            // Main structure
            display.innerHTML = `
                <div class="cardamom-wrapper">
                    <h2>${key}</h2>
                    <div class="carousel">
                        ${slides}
                        <button class="prev">⬅</button>
                        <button class="next">➡</button>
                    </div>
                    <div class="dots">${dots}</div>
                </div>
            `;

            // JS logic for carousel
            const slidesEls = display.querySelectorAll(".child-slide");
            const dotsEls = display.querySelectorAll(".dot");
            let current = 0;

            function showSlide(index) {
                slidesEls.forEach((slide, i) => slide.classList.toggle("active", i === index));
                dotsEls.forEach((dot, i) => dot.classList.toggle("active", i === index));
                current = index;
            }

            display.querySelector(".prev").addEventListener("click", () => {
                let newIndex = (current - 1 + slidesEls.length) % slidesEls.length;
                showSlide(newIndex);
            });

            display.querySelector(".next").addEventListener("click", () => {
                let newIndex = (current + 1) % slidesEls.length;
                showSlide(newIndex);
            });

            dotsEls.forEach(dot => {
                dot.addEventListener("click", () => {
                    showSlide(parseInt(dot.dataset.index));
                });
            });
        })
        .catch(err => {
            console.error("Error fetching JSON:", err);
            display.innerHTML = "<p>⚠ Failed to load price data.</p>";
        });
});
