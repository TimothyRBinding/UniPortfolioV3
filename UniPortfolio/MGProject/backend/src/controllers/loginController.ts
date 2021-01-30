const bcrypt = require('bcryptjs')
var { validationResult } = require('express-validator')
const jwt = require('jwt-simple')

import { User } from '../database/entity/User'
import { getRepository } from 'typeorm'

const JWT_SECRET = 'z3r0Wa3te'

async function loginUser(req, res) {
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
            const existingUser = await getRepository(User)
                .createQueryBuilder('User')
                .where('User.username = :username', {
                    username: req.body.username,
                })
                .getOne()
            try {
                // Load hash from your password DB.
                bcrypt.compare(
                    req.body.password,
                    existingUser.hashedPassword,
                    function (err, result) {
                        if (req.body.username != existingUser.username) {
                            // Status code = 403: Authentication error status
                            return res.status(403).send({
                                error:
                                    'Username was incorrect. Please enter the correct username.',
                            })
                        } else if (!result) {
                            return res.status(403).send({
                                error:
                                    'Password was incorrect. Please enter the correct password.',
                            })
                        } else {
                            var sessionToken = jwt.encode(
                                existingUser,
                                JWT_SECRET,
                            )

                            return res.status(202).send({
                                token: `Session token: ${sessionToken}`,
                                success: `${existingUser.username} you have successfully logged in.`,
                                userID: existingUser.id,
                            })
                        }
                    },
                )
            } catch {
                res.status(422).send({
                    error: 'Error occured while logging in.',
                })
            }
        }
    } catch {
        res.status(422).send({
            error: 'Error validating user login.',
        })
    }
}

export default { loginUser }
