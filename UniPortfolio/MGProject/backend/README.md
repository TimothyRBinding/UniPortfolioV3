# How to Run the Zero Waste App API?

## Install MySQL

You must have a local mysql server running in order to run the backend API. [This](https://youtu.be/HXV3zeQKqGY?t=3148) tutorial will talk you through how to install it for either Windows or MacOS. Ensure that your mysql server is running.

## Create a Database on Your Local MySQL Server

This can be done through various GUIs or the mysql CLI.

## Create a ormconfig.json File

This file contains the details required by typeORM to connect to your local database. Create the file and copy and paste the contents bellow, filling in all of the details in {} with the description of the details inside.

```json
{
    "type": "mysql",
    "host": "localhost",
    "port": "{Your mysql local server port}",
    "username": "{Your mysql local server username}",
    "password": "{Your mysql local server password}",
    "database": "{The name of the local database you created}",
    "synchronize": true,
    "logging": false,
    "entities": ["src/database/entity/**/*.ts"],
    "migrations": ["src/database/migration/**/*.ts"],
    "subscribers": ["src/database/subscriber/**/*.ts"],
    "cli": {
        "entitiesDir": "src/database/entity",
        "migrationsDir": "src/database/migration",
        "subscribersDir": "src/database/subscriber"
    }
}
```

## You're All Set!

Enjoy running this API :D
