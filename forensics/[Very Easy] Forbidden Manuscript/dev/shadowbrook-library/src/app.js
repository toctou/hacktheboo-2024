const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const manuscriptRoutes = require('./routes/manuscripts');
const indexRoutes = require('./routes/index');
const app = express();

// Middleware
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, 'public')));

// View engine setup
app.set('view engine', 'ejs');
app.set('views', path.join(__dirname, 'views'));

// Routes
app.use('/', indexRoutes);
app.use('/manuscripts', manuscriptRoutes);

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
    console.log(`Shadowbrook Library is running on port ${PORT}`);
});
