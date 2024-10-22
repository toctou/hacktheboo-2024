const express = require('express');
const router = express.Router();
const { template } = require("@blakeembrey/template"); // Use require instead of import

// 1. GET: Home page
router.get('/', (req, res) => {
    const { user } = req.query; // Optional query parameter to pass user's name
    
    let additionalContent = '';

    if (user) {
        try {
            const decodedUser = decodeURIComponent(user);
            console.log('User:', decodedUser);
            const fn = template("Welcome back, {{user}}!", decodedUser);
            const userRender = fn({ user: decodedUser });
        
            additionalContent = `
                <p><strong>${userRender}</strong> Your knowledge quest continues. Browse the hidden manuscripts or leave your own wisdom behind.</p>
                <a class="button spooky-button" href="/manuscripts/add">Contribute a Manuscript</a>
            `;
        } catch (error) {
            console.error('Error decoding or rendering user:', error);
            additionalContent = ''; // Render nothing if error occurs
        }
    } else {
        additionalContent = `
            <form action="/" method="GET" class="username-form">
                <label for="username">Enter your name to personalize your journey:</label>
                <input type="text" id="username" name="user" placeholder="Your Name" required>
                <button type="submit" class="button spooky-button">Enter the Vault</button>
            </form>
        `;
    }

    const content = `
        <section class="home-section">
            <h2>Welcome to the Forbidden Vault of Knowledge</h2>
            <p>Hello, ${user || 'Adventurer'}! Dare to enter? Search the library, or contribute your own arcane manuscript.</p>
            <a class="button spooky-button" href="/manuscripts/search">Search the Vault</a>
            ${additionalContent}
        </section>
    `;

    // Safely render the layout and pass the content to be injected
    try {
        res.render('layouts/main', { title: "Welcome to Shadowbrook Library", content });
    } catch (renderError) {
        console.error('Error rendering the page:', renderError);
        res.status(200).send(''); // Return empty response in case of error
    }
});

module.exports = router;
