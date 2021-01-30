import * as express from 'express'
import signupController from '../controllers/signupController'
const { check } = require('express-validator')
const router = express.Router()

// Signup endpoint which takes a post request and returns a message with name entered.

router.post(
    '/',
    [
        check('firstName')
            .not()
            .notEmpty()
            .withMessage('Please enter a first name for the registration.')
            .isLength({ min: 3 })
            .withMessage('First name must be at least 3 characters long')
            .not()
            .isEmail()
            .withMessage('First Name can not be a email.'),
        check('lastName')
            .not()
            .notEmpty()
            .withMessage('Please enter a last name for the registration.')
            .isLength({ min: 3 })
            .withMessage('Last name must be at least 3 characters long')
            .not()
            .isEmail()
            .withMessage('Last Name can not be a email.'),
        check('username')
            .not()
            .notEmpty()
            .exists()
            .withMessage('Username already exists')
            .isLength({ min: 5 })
            .withMessage('Username must have at least 5 characters.')
            .not()
            .isEmail()
            .withMessage('Username can not be a email.'),
        check('emailAddress')
            .not()
            .notEmpty()
            .withMessage('Please enter a email address for the registration.')
            .isEmail()
            .withMessage('Please enter a valid email address.')
            .exists()
            .withMessage('This email address is already registered.'),
        check('password')
            .not()
            .notEmpty()
            .withMessage('Please enter a password for the registration.')
            .isLength({ min: 8 })
            .withMessage('Password needs to be 8 charcters or more')
            .matches(
                /^(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[!@#$%^&*()_+\-=\[\]{};':"\\|,.<>\/?]).{8,}$/,
            )
            .withMessage(
                'Password must contain at least a number, letter and a special character.',
            )
            .custom((value, { req, loc, path }) => {
                if (value !== req.body.confirmPassword) {
                    // trow error if passwords do not match
                    throw new Error('Passwords do not match')
                } else {
                    return value
                }
            }),
    ],
    signupController.createUser,
)

export default router
