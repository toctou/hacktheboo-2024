const express = require('express');
const router = express.Router();
const db = require('../config/db');

// 1. GET: Search Manuscripts
router.get('/search', (req, res) => {
    const { query = '', user } = req.query; // Default query to an empty string if not provided

    const searchQuery = `%${query}%`;
    db.all("SELECT * FROM manuscripts WHERE title LIKE ? OR content LIKE ?", [searchQuery, searchQuery], (err, rows) => {
        if (err) {
            res.status(500).send("Error querying the database.");
            return;
        }

        // Generate dynamic HTML for search input and results
        let content = `
            <section class="search-results">
                <h2>Search Manuscripts</h2>
                <form action="/manuscripts/search" method="get" class="search-form">
                    <input type="text" name="query" value="${query}" placeholder="Search for manuscripts..." required />
                    <button type="submit">Search</button>
                </form>
                <ul>
        `;

        if (rows.length > 0) {
            rows.forEach(manuscript => {
                content += `
                    <li>
                        <a href="/manuscripts/view/${manuscript.id}">${manuscript.title}</a>
                    </li>
                `;
            });
        } else {
            content += `
                <li>No results found for "${query}".</li>
            `;
        }

        content += `
                </ul>
            </section>
        `;

        // Render the layout and inject the dynamic content as a string
        res.render('layouts/main', { title: `Search Results for "${query}"`, content, user });
    });
});


// 2. GET: View a single manuscript by ID
router.get('/view/:id', (req, res) => {
    const { id } = req.params;
    const { user } = req.query;

    db.get("SELECT * FROM manuscripts WHERE id = ?", [id], (err, manuscript) => {
        if (err || !manuscript) {
            res.status(404).send("Manuscript not found.");
            return;
        }

        // Generate dynamic content for the manuscript view
        const content = `
            <section class="manuscript-view">
                <h2>${manuscript.title}</h2>
                <p><strong>Author:</strong> ${manuscript.author}</p>
                <article>
                    <p>${manuscript.content}</p>
                </article>
            </section>
        `;

        // Render the layout and inject the dynamic content
        res.render('layouts/main', { title: manuscript.title, content, user });
    });
});

// 3. GET: Add Manuscript form
router.get('/add', (req, res) => {
    const { user } = req.query;

    // Generate content for the add manuscript form
    const content = `
        <section class="add-manuscript">
            <h2>Add a New Arcane Manuscript</h2>
            <form action="/manuscripts/add" method="POST">
                <label for="title">Title:</label>
                <input type="text" id="title" name="title" required>

                <label for="author">Author:</label>
                <input type="text" id="author" name="author" required>

                <label for="content">Content:</label>
                <textarea id="content" name="content" rows="6" required></textarea>

                <button type="submit" class="button spooky-button">Submit Manuscript</button>
            </form>
        </section>
    `;

    // Render the layout and inject the form
    res.render('layouts/main', { title: "Add a New Manuscript", content, user });
});

// 4. POST: Add a New Manuscript
router.post('/add', (req, res) => {
    const { title, author, content } = req.body;
    const { user } = req.query;

    db.run("INSERT INTO manuscripts (title, author, content) VALUES (?, ?, ?)", [title, author, content], function(err) {
        if (err) {
            res.status(500).send("Error inserting into the database.");
            return;
        }

        // After adding, redirect to the newly added manuscript's page
        res.redirect(`/manuscripts/view/${this.lastID}?user=${user}`);
    });
});

module.exports = router;
