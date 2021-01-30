import * as express from 'express'
import businessController from '../controllers/businessController'
const router = express.Router()

router.get('/photos', businessController.getAllBusinessImages)
router.get('/openingTimes', businessController.getAllOpeningTimes)
router.get('/', businessController.getAllBusinesses)
router.get('/:id', businessController.getBusinessById)
router.post('/', businessController.addNewBusiness)

export default router
