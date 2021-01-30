import * as express from 'express'

const router = express.Router()
import businesses from './businesses'
import locationMarkers from './locationMarkers'
import searchBar from '../routes/searchBar'
import reviews from './reviews'
import userLogin from './userLogin'
import userSignup from './userSignup'
// Code runs when a client sends a HTTP requests to this server. Related functions are stored in their own file in the 'routes' folder. These modules/files will be required here in this module to use in each request listeners callback function.

// all routes for a business is stored in this routes file
router.use('/businesses', businesses)
router.use('/locationMarkers', locationMarkers)
router.use('/reviews', reviews)
router.use('/signup', userSignup)
router.use('/login', userLogin)

router.use('/search', searchBar)

// Signup endpoint which takes a post request and returns a message with name entered.
// Posts a confirmation message to the browser's console.
// To confirm the user was registered. This is just a success message

router.post('/signup', (req, res) => {
    res.send({
        message: `Hello ${req.body.firstName} ${req.body.lastName}! Your user was registered! Have fun!`,
    })
})

router.get('/login', (req, res) => {
    res.statusCode = 200

    res.json('Login Logic ')
})

router.get('/signup', (req, res) => {
    res.statusCode = 200
    res.json('Signup Login')
})

//router.get('/search/:searchString', (req, res) => {})

// Safety route in case no other endpoint meets the url requested from the client
router.get('/*', (req, res) => {
    res.statusCode = 404
    res.json('I am sorry but the resource requested was not found.')
})

export default router
