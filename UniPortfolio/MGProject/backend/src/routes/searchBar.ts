import * as express from 'express'
import searchBarController from '../controllers/searchBarController'
const router = express.Router()

router.get('/', searchBarController.getAllLocationsAndBuisnesses)

export default router