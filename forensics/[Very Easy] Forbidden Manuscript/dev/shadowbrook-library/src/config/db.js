const sqlite3 = require('sqlite3').verbose();
const fs = require('fs');
const path = require('path');

// Define the database path
const dbDirectory = path.join(__dirname, '../data');
const dbPath = process.env.DB_PATH || path.join(dbDirectory, 'shadowbrook.db');

// Ensure the database directory exists
if (!fs.existsSync(dbDirectory)) {
    console.log(`Directory '${dbDirectory}' does not exist. Creating...`);
    fs.mkdirSync(dbDirectory, { recursive: true });
}

// Connect to SQLite database
const db = new sqlite3.Database(dbPath, (err) => {
    if (err) {
        console.error('Error connecting to SQLite database:', err.message);
    } else {
        console.log('Connected to SQLite database.');
        
        // Create manuscripts table if it doesn't exist
        db.run(`CREATE TABLE IF NOT EXISTS manuscripts (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL,
            author TEXT NOT NULL,
            content TEXT NOT NULL
        )`, (err) => {
            if (err) {
                console.error('Error creating manuscripts table:', err.message);
            } else {
                console.log('Manuscripts table ready.');

                // Initialize database with creepy Halloween-themed manuscripts
                const manuscripts = [
                    {
                        title: "The Whispering Shadows",
                        author: "Unknown",
                        content: "In the dead of night, the shadows in the old library seem to move, whispering secrets of those long forgotten. Some say they hear faint voices calling their name..."
                    },
                    {
                        title: "The Cursed Pumpkin",
                        author: "Edgar Fallow",
                        content: "Every year, the pumpkin with a face twisted in agony reappears on the doorstep of the abandoned house. Its origins remain unknown, but those who dare carve it disappear without a trace."
                    },
                    {
                        title: "The Haunting of Willow Lane",
                        author: "Mary Blackthorn",
                        content: "A house once full of life now stands as a decrepit shell. At midnight, the laughter of children echoes through the halls, though none have lived there for decades..."
                    },
                    {
                        title: "The Witch's Grimoire",
                        author: "Seraphina Nightshade",
                        content: "Bound in human skin, the Witch's Grimoire contains forbidden spells. It is said those who read its pages under a blood moon shall be granted immense power — but at a terrible cost."
                    },
                    {
                        title: "The Mask of Eternal Night",
                        author: "Mortimer Graves",
                        content: "A porcelain mask with hollow eyes sits locked away in a museum. Legends tell that wearing it opens a portal to a realm of endless darkness, where souls are consumed for eternity."
                    }
                ];

                const insertManuscript = db.prepare(`INSERT INTO manuscripts (title, author, content) VALUES (?, ?, ?)`);
                
                manuscripts.forEach((manuscript) => {
                    insertManuscript.run(manuscript.title, manuscript.author, manuscript.content, (err) => {
                        if (err) {
                            console.error('Error inserting manuscript:', err.message);
                        } else {
                            console.log(`Manuscript "${manuscript.title}" added.`);
                        }
                    });
                });
                
                insertManuscript.finalize();
            }
        });
    }
});

module.exports = db;
