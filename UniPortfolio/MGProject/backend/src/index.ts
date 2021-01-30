import * as dotenv from 'dotenv'
import * as express from 'express'
import * as bodyParser from 'body-parser'
import * as cors from 'cors'
import * as morgan from 'morgan'
import * as session from 'express-session'

import routes from './routes'
import 'reflect-metadata'
import { createConnection } from 'typeorm'

// loads all of the environment variable into the global object 'process.env' so we can use them throughout the project
dotenv.config()

// Connect to the database using the configuration in the ormconfig.json
createConnection().then(async (connection) => {
    const app = express()
    

    // parses the body of requests into the req.body object in a json format
    app.use(bodyParser.json({ limit: '50mb', extended: true }))

    // allow requests from our frontend by configuring cors
    const corsOptions = { origin: process.env.FRONTEND_URL }
    app.use(cors(corsOptions))
    // used for allowing preliminary requests to occur on all resouces available on this server
    app.options('*', cors())

    // Sends any activity to the console/terminal.
    app.use(morgan('combined'))
    
    app.use(session({
        name: process.env.SESS_NAME,
        secret: 'psaib66mxzhqhxe1ozbq', // Each time a cookie is return to the user, it will be signed with a secret(what are we using to hash the cookie).
        resave: false,                  // Each time the page is reloaded, resave and update the session.
        saveUninitialized: false,       // Create a cookie and a session, for when a user visits the application, even if they have not logged in.
        cookie: { 
            sameSite: true,
            secure: false 
        }
    }))
    // For all of the routes, use the routes specified in the routes module
    app.use('/', routes)

    // HTTP server starts listening on the port (specified in the .env file)
    app.listen(
        process.env.API_PORT,
        console.log(
            '\x1b[35m',
            `Zero Waste Locations API 🌳🌳🌳 running here: http://localhost:${process.env.API_PORT}/ `,
            '\x1b[37m',
        ),
    )
})
