const bcrypt = require('bcryptjs')
const { check, validationResult } = require('express-validator')

import { getRepository } from 'typeorm'
import { User } from '../database/entity/User'

// Posts a confirmation message to the browser's console.
// To confirm the user was registered. This is just a success message.
async function createUser(req, res) {
    const userRepository = await getRepository(User)
    const newUser = new User()

    try {
        // Finds the validation errors in this request and wraps them in an object with handy functions.
        const errors = validationResult(req)
        console.log(req.body)
        if (!errors.isEmpty()) {
            console.log(errors)
            return res.status(422).json({
                errors: errors.array(),
            })
        } else {
            try {
                const existingUsername = await getRepository(User)
                    .createQueryBuilder('User')
                    .where('User.username = :username', {
                        username: req.body.username,
                    })
                    .getOne()

                const existingEmailAddress = await getRepository(User)
                    .createQueryBuilder('User')
                    .where('User.emailAddress = :emailAddress', {
                        emailAddress: req.body.emailAddress,
                    })
                    .getOne()

                if (existingUsername) {
                    return res.status(403).send({
                        error: 'Username already exists!',
                    })
                } else if (existingEmailAddress) {
                    return res.status(403).send({
                        error: 'Email address already exists!',
                    })
                } else {
                    bcrypt.genSalt(10, function (err, salt) {
                        bcrypt.hash(req.body.password, salt, async function (
                            err,
                            hash,
                        ) {
                            // Store hash in your password DB.
                            newUser.firstName = req.body.firstName
                            newUser.lastName = req.body.lastName
                            newUser.username = req.body.username
                            newUser.emailAddress = req.body.emailAddress
                            newUser.hashedPassword = hash
                            newUser.dateCreated = new Date()

                            let userJustAdded = await userRepository.save(
                                newUser,
                            )
                            res.status(202).json({
                                success: `Hello ${req.body.firstName} ${req.body.lastName}! Your user was registered!`,
                                userID: userJustAdded.id,
                            })
                        })
                    })
                }
            } catch {
                res.status(422).send({
                    error:
                        'Error saving record to database. Database does not exist!',
                })
            }
        }
    } catch {
        res.status(422).send({
            error: 'Error validating user registration.',
        })
    }
}
export default { createUser }
