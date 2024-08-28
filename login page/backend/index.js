
const express = require('express');
const mysql = require('mysql2');
const bodyParser = require('body-parser');

const app = express();
const port = 3000;

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());


const connection = mysql.createConnection({
    host: 'localhost',
    user: 'root', 
    password: 'cse', 
    database: 'webapp'
});

connection.connect((err) => {
    if (err) {
        console.error('Error connecting to database: ' + err.stack);
        return;
    }
    console.log('Connected to MySQL database');
});
app.post('/login', (req, res) => {
    const { username, password } = req.body;
    connection.query(
        'SELECT * FROM users WHERE username = ? AND password = ?',
        [username, password],
        (error, results, fields) => {
            if (error) {
                res.status(500).json({ error });
            } else {
                if (results.length > 0) {
                    res.status(200).json({ message: 'Login successful' });
                } else {
                    res.status(401).json({ message: 'Invalid credentials' });
                }
            }
        }
    );
});
app.listen(port, () => {
    console.log(`Server is running on http://localhost:${port}`);
});
