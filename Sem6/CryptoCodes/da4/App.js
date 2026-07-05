const express = require('express');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');
const cors = require('cors');

dotenv.config();
const app = express();
app.use(express.json());
app.use(cors());

const PORT = 3000;
const users = [{ username: "apoorva", password: "apoorvakarnwal" }];

app.post('/login', (req, res) => {
    const { username, password } = req.body;
    const user = users.find(u => u.username === username && u.password === password);
    if (!user) return res.status(401).json({ message: "Invalid credentials" });
    const token = jwt.sign({username}, process.env.JWT_SECRET, {expiresIn: '1h' });
    res.json({ token });
});

app.get('/secured', authenticateToken, (req, res) => {
    res.json({ message: "You have access to secured data!", user: req.user });
});

function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization'];
    const token = authHeader && authHeader.split(' ')[1];
    if (!token) return res.status(403).json({ message: "Token required" });

    jwt.verify(token, process.env.JWT_SECRET, (err, user) => {
        if (err) return res.status(403).json({ message: "Invalid token" });
        req.user = user;
        next();
    });
}

app.listen(PORT, () => console.log(`Server running on http://localhost:${PORT}`));

