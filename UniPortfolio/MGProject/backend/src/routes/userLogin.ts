import * as express from 'express'
import loginController from '../controllers/loginController'
const { check } = require('express-validator')
const router = express.Router()

// Login endpoint which takes a post request and returns a message depending on the outcome.
router.post(
    '/',
    [
        check('username')
            .not()
            .notEmpty()
            .withMessage('Please enter a username to login.')
            .not()
            .isEmail()
            .withMessage('Username can not be a email.'),
        check('password')
            .not()
            .notEmpty()
            .withMessage('Please enter a password to login.'),
    ],
    loginController.loginUser,
)

export default router
